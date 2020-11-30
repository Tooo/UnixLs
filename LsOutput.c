#include <stdio.h>

#include "LsOutput.h"

void printOptions(bool optioni, bool optionl, bool optionR) {
    printf("Option i = %d\n", optioni);
    printf("Option l = %d\n", optionl);
    printf("Option R = %d\n", optionR);
}

void printFilename(char * filename) {
    printf("%s\n", filename);
}

void printInode(long inode) {
    printf("%ld ", inode);
}