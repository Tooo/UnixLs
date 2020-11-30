#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "LsOutput.h"
#include "LsFile.h"

int main (int arc, char** args) {
    bool optioni = false;
    bool optionl = false;
    bool optionR = false;
    int argCounter = 1;

    while (arc > argCounter && args[argCounter][0] == '-') {
        int strLength = strlen(args[argCounter]);
        for (int i = 1; i < strLength; i++) {
            switch (args[argCounter][i]) {
                case 'i':
                    optioni = true;
                    setOptioni(true);
                    break;
                case 'l':
                    optionl = true;
                    setOptionl(true);
                    break;
                case 'R':
                    optionR = true;
                    setOptionR(true);
                    break;
                default:
                    break;
            }
        }
        argCounter++;
    }

    printOptions(optioni, optionl, optionR);

    char ** directories = &args[argCounter];
    int dirCount = arc-argCounter;
    for (int i = 0; i < dirCount; i++) {
        printDirectory(directories[i]);
    }
    return 0;
}