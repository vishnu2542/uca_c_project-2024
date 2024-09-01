// test_rawstats.c
#include <stdio.h>
#include "rawstats.h"

int main() {
    double data[] = {1.5, 2.5, 3.0, 2.5, 4.5, 5.0};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Mean: %.2f\n", mean(data, n));
    printf("Median: %.2f\n", median(data, n));
    double modeResult = mode(data, n);
    if (modeResult != -1) {
        printf("Mode: %.2f\n", modeResult);
    }

    return 0;
}
