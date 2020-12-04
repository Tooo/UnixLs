#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <unistd.h>

#include <stdio.h>

#include "LsFile.h"
#include "UnixLs.h"
#include "LsOutput.h"
#include "list.h"

static List * directories;

int File_setup() {
    directories = List_create();
    if (!directories) {
        return 1;
    }
    return 0;
}

void File_readDirectory(char * dirName) {
    struct stat buf;
    int result = stat(dirName, &buf);
    if (result) {
        result = lstat(dirName, &buf);
    }

    if (!S_ISDIR(buf.st_mode)) {
        File_readFile(dirName);
        printFilename(dirName);
        return;
    }
    DIR * dir = opendir(dirName);
    char * dirNameCopy = malloc(sizeof(dirName));
    strcpy(dirNameCopy, dirName);
    List_prepend(directories, dirNameCopy);
    closedir(dir);
}

void File_readFile(char * fileName) {
    struct stat buf;
    int result = stat(fileName, &buf);
    if (result) {
        result = lstat(fileName, &buf);
        if (result) {
            printNoFile(fileName);
            return;
        } 
    }

    if (getOptioni()) {
        printInode(buf.st_ino);
    }

    if (getOptionl()) {    
        printl(buf);
    }
}

char * File_getNameFromID(int userID) {
    struct passwd * pwd = getpwuid(userID);
    return pwd->pw_name;
}

void File_runDirectory() {
    while (List_count(directories)) {
        char * dirName = List_trim(directories);
        DIR * dir = opendir(dirName);

        if (!dir) {
            free (dirName);
            continue;
        }

        printNewLine();
        printDirectory(dirName);
        struct dirent * dp;
        while ((dp = readdir(dir)) != NULL) {
            if (dp->d_name[0] == '.') {
                continue;
            }
            struct stat buf;
            char path[512];
            sprintf(path, "%s/%s", dirName, dp->d_name);
            stat(path, &buf);

            File_readFile(path);
            printFilename(dp->d_name);

            if (getOptionR()) {
                if (S_ISDIR(buf.st_mode)) {
                    char * pathCopy = malloc(sizeof(path));
                    strcpy(pathCopy, path);
                    List_append(directories, pathCopy);
                }
            }
        }
        free(dirName);
        closedir(dir);
    }
}