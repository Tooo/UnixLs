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

void File_readDirectory(char * dirName) {
    DIR * dir = opendir(dirName);
    if (!dir) {
        File_readFile(dirName);
        return;
    }

    struct dirent * dp;

    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_name[0] == '.') {
            continue;
        }
        struct stat buf;
        char path[512];
        sprintf(path, "%s/%s", dirName, dp->d_name);
        int result = stat(path, &buf);

        if (getOptioni()) {
            printInode(dp->d_ino);
        }

        if (getOptionl()) {
            if (result) {
                printf("ERROR: %s cannot be read\n", dp->d_name);
                continue;
            }
            printl(buf);
        }

        printFilename(dp->d_name);
    }
    
    closedir(dir);
}

void File_readFile(char * fileName) {
    struct stat buf;
    int result = stat(fileName, &buf);
    if (result) {
        printNoFile(fileName);
        return;
    }

    if (getOptioni()) {
        printInode(buf.st_ino);
    }

    if (getOptionl()) {    
        printl(buf);
    }
    printFilename(fileName);
}

char * File_getNameFromID(int userID) {
    struct passwd * pwd = getpwuid(userID);
    return pwd->pw_name;
}