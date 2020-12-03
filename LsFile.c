#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include <stdio.h>

#include "LsFile.h"
#include "UnixLs.h"
#include "LsOutput.h"

void File_readDirectory(char * dirName) {
    DIR * dir = opendir(dirName);
    struct dirent * dp;

    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_name[0] == '.') {
            continue;
        }
        struct stat buf;
        int result = stat(dp->d_name, &buf);
        if (result == -1) {
            result = lstat(dp->d_name, &buf);
        }

        if (getOptioni()) {
            printInode(dp->d_ino);
        }

        if (getOptionl()) {
            printl(buf);
        }

        printFilename(dp->d_name);
    }
    
    closedir(dir);
}