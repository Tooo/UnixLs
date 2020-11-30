#include <stdio.h>

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