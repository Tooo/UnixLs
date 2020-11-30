#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include <stdio.h>

#include "LsFile.h"
#include "UnixLs.h"

void readDirectory(char * dirName) {
    DIR * dir = opendir(".");
    struct dirent * dp = readdir(dir);
    struct stat * buf;

    stat(dp->d_name, buf);
    printf("%s\n", buf->st_ino);
    closedir(dir);
}