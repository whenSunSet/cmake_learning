//
// Created by 何时夕 on 2018/10/20.
//
#include <stdio.h>
#include <cmath>
#include "MathFunctions.h"
#include "Configure.h"

double mysqrt(double x) {
    if (x <= 0) {
        return 0;
    }

    double result;
    double delta;
    result = x;

    // do ten iterations
    int i;
    for (i = 0; i < 10; ++i) {
        if (result <= 0) {
            result = 0.1;
        }
        delta = x - (result * result);
#if defined (HAVE_LOG) && defined (HAVE_EXP)
        result = exp(log(x)*0.5);
#else
        result = result + 0.5 * delta / result;
#endif
        fprintf(stdout, "Computing sqrt of %g to be %g\n", x, result);
    }
    return result;
}

