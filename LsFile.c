#include <stdlib.h>
#include <stdbool.h>

#include "LsFile.h"

static bool optioni = false;
static bool optionl = false;
static bool optionR = false;

void setOptioni(bool option) {
    optioni = option;
}

void setOptionl(bool option) {
    optionl = option;
}

void setOptionR(bool option) {
    optionR = option;
}