#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

#include "LsOutput.h"
#include "LsFile.h"

void printNewLine() {
    printf("\n");
}

void printDirectory(char * directory) {
    printf("%s:\n", directory);
}

void printFilename(char * filename) {
    printf("%s\n", filename);
}

void printInode(long inode) {
    printf("%ld ", inode);
}

void printl(struct stat buf) {
    printPermission(buf.st_mode);
    printf("%ld ", buf.st_nlink);
    printf("%s ", File_getNameFromID(buf.st_uid));
    printf("%s ", File_getNameFromID(buf.st_gid));
    printf("%5ld ", buf.st_size);
    printDate(buf.st_mtim);
}

void printPermission(mode_t mode) {
    if (S_ISDIR(mode)) {
        printf("d");
    } else {
        printf("-");
    }
    char rwx[9] = "rwxrwxrwx";
    int permission[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
    for (int i = 0; i < 9; i++) {
        if (mode & permission[i]) {
            printf("%c", rwx[i]);
        } else {
            printf("-");
        }
    }
    printf(" ");
}

void printDate(struct timespec time) {
    time_t seconds = time.tv_sec;
    struct tm * local = localtime(&seconds);

    char * months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("%s %2d ", months[local->tm_mon], local->tm_mday);
    printf("%02d:%02d ", local->tm_hour, local->tm_min);
}