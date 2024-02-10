// kernel_axpy.cpp
#include "kernel_axpy.h"

void saxpy(int n, float a, const float *x, float *y)
{
    for(int i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i];  // SAXPY operation
    }
}
