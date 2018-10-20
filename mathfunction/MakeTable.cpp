//
// Created by 何时夕 on 2018/10/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main (int argc, char *argv[]) {
    double result;
    if (argc < 2) {
        return 1;
    }
    FILE *fout = fopen(argv[1], "w");
    if (!fout) {
        return 1;
    }
    fprintf(fout, "double sqrtTable[] = {\n");
    for (int j = 0; j < 10; ++j) {
        result = sqrt(static_cast<double>(j));
        fprintf(fout, "%g,\n", result);
    }
    fprintf(fout, "0};\n");
    fclose(fout);
    return 0;
}

