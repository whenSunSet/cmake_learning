//
// Created by 何时夕 on 2018/10/20.
// 1.cmake 的命令允许大小写混用， 但是变量名是区分大小写的。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stdout, "usage: %s number\n", argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}

