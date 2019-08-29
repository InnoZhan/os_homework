#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int i;
    float f;
    double d;

    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;

    printf("Max int value: %d, size: %d\n", i, sizeof(i));
    printf("Max float value: %.10e, size: %d\n", f, sizeof(f));
    printf("Max double value: %.10e, size: %d\n", d, sizeof(d));

    return 0;
}