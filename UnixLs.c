#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "LsOutput.h"

static bool optioni = false;
static bool optionl = false;
static bool optionR = false;

int main (int arc, char** args) {
    int argCounter = 1;

    while (arc > argCounter && args[argCounter][0] == '-') {
        int strLength = strlen(args[argCounter]);
        for (int i = 1; i < strLength; i++) {
            switch (args[argCounter][i]) {
                case 'i':
                    optioni = true;
                    break;
                case 'l':
                    optionl = true;
                    break;
                case 'R':
                    optionR = true;
                    break;
                default:
                    break;
            }
        }
        argCounter++;
    }

    printOptions(optioni, optionl, optionR);

    return 0;
}