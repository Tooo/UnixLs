#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

#include <stdio.h>

#include "LsFile.h"
#include "UnixLs.h"
#include "LsOutput.h"
#include "list.h"

static List * directories;
static bool needSpacing = false;
static bool needDirectoryName = false;

int File_setup() {
    directories = List_create();
    if (!directories) {
        printError("List");
        return 1;
    }

    if (getOptionR()) {
        needDirectoryName = true;
    }
    return 0;
}

void File_setNeedDirectoryName(bool value) {
    needDirectoryName = true;
}

void File_readDirectory(char * dirName) {
    struct stat buf;
    int result = stat(dirName, &buf);
    if (result) {
        result = lstat(dirName, &buf);
    }

    if (result || !S_ISDIR(buf.st_mode)) {
        needSpacing = true;
        File_readFile(dirName, dirName);
        return;
    }

    DIR * dir = opendir(dirName);
    char * dirNameCopy = strdup(dirName);
    if (!dirNameCopy) {
        printError("String copy");
    } else {
        List_prepend(directories, dirNameCopy);
    }
    
    closedir(dir);
}

void File_readFile(char * path, char * fileName) {
    struct stat buf;
    int result = stat(path, &buf);
    if (result) {
        result = lstat(path, &buf);
        if (result) {
            printNoFile(path);
            return;
        } 
    }

    if (getOptioni()) {
        printInode(buf.st_ino);
    }

    if (getOptionl()) {    
        printl(buf);
    }

    printFilename(fileName);

    if (S_ISLNK(buf.st_mode)) {
        char link[512] = {};
        readlink(path, link, 512);
        printLink(link);
    }

    printNewLine();
}

char * File_getNameFromID(int userID) {
    struct passwd * pwd = getpwuid(userID);
    return pwd->pw_name;
}

char * File_getGroupFromID(int groupID) {
    struct group *grp = getgrgid(groupID);
    return grp->gr_name;
}

void File_runDirectory() {
    while (List_count(directories)) {
        char * dirName = List_trim(directories);
        DIR * dir = opendir(dirName);

        if (!dir) {
            free (dirName);
            continue;
        }

        if (needSpacing) {
            printNewLine();
        } else {
            needSpacing = true;
        }
        
        if (needDirectoryName) {
            printDirectory(dirName);
        } else {
            needDirectoryName = true;
        }

        struct dirent * dp;
        while ((dp = readdir(dir)) != NULL) {
            if (dp->d_name[0] == '.') {
                continue;
            }
            char path[512];
            sprintf(path, "%s/%s", dirName, dp->d_name);

            File_readFile(path, dp->d_name);

            if (getOptionR()) {
                struct stat buf;
                stat(path, &buf);
                if (S_ISDIR(buf.st_mode)) {
                    char * pathCopy = strdup(path);
                    if (!pathCopy) {
                        printError("String copy");
                    }
                    List_append(directories, pathCopy);
                }
            }
        }
        free(dirName);
        closedir(dir);
    }
}