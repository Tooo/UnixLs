#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "UnixLs.h"
#include "LsOutput.h"
#include "LsFile.h"

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

    char ** directories = &args[argCounter];
    int dirCount = arc-argCounter;

    if (dirCount == 0) {
        readDirectory(".");
        return 0;
    } else if (dirCount == 1) {
        readDirectory(directories[0]);
        return 0;
    }

    for (int i = 0; i < dirCount-1; i++) {
        printDirectory(directories[i]);
        readDirectory(directories[i]);
        printNewLine();
    }

    printDirectory(directories[dirCount-1]);
    readDirectory(directories[dirCount-1]);

    return 0;
}

bool getOptioni() {
    return optioni;
}

bool getOptionl() {
    return optionl;
}

bool getOptionR() {
    return optionR;
}