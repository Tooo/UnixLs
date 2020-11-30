#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#include "LsOutput.h"

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
    printf("%d ", buf.st_uid);
    printf("%d ", buf.st_gid);
    printf("%5ld ", buf.st_size);
    printDate(buf.st_mtim);
}

void printPermission(mode_t mode) {
}

void printDate(struct timespec time) {
}