#include <stdio.h>
#include "guido.h"

#ifndef DEBUG
#define DEBUG
#endif

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s N X_values D_values\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    double *X = (double*)malloc(n * sizeof(double));
    double *D = (double*)malloc(n * sizeof(double));
    double *Xout_sw = (double*)malloc(n * sizeof(double));

    // Parse X values
    for (int i = 0; i < n; i++) {
        X[i] = atof(argv[2 + i]);
    }

    // Parse D values
    for (int i = 0; i < n; i++) {
        D[i] = atof(argv[2 + n + i]);
    }




