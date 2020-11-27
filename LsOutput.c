#include <stdio.h>

#include "LsOutput.h"

void printOptions(bool optioni, bool optionl, bool optionR) {
    printf("Option i = %d\n", optioni);
    printf("Option l = %d\n", optionl);
    printf("Option R = %d\n", optionR);
}

void printDirectory(char ** dirs, int dirc) {
    for (int i = 0; i < dirc; i++) {
        printf("Directory: %s\n", dirs[i]);
    }
}