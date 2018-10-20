//
// Created by 何时夕 on 2018/10/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stdout, "%s version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        fprintf(stdout, "usage: %s number\n", argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout, "the square root of %g is %g\n", inputValue, outputValue);
    return 0;
}

