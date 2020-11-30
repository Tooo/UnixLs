#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include <stdio.h>

#include "LsFile.h"
#include "UnixLs.h"

void readDirectory(char * dirName) {
    DIR * dir = opendir(".");
    struct dirent * dp = readdir(dir);
    struct stat buf;

    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_name[0] == '.') {
            continue;
        }
        stat(dp->d_name, &buf);
        printf("%ld ", buf.st_ino);
        printf("%s\n", dp->d_name);
    }
    
    closedir(dir);
}