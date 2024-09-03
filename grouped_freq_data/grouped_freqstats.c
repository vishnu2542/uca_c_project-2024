// grouped_freqstats.c
#include "grouped_freqstats.h"
#include <stdlib.h>

// Function to calculate mean for grouped frequency distribution
double mean_grouped(double lower[], double upper[], int freq[], int n) {
    double sum_fx = 0.0;
    int total_freq = 0;

    for (int i = 0; i < n; i++) {
        double mid = (lower[i] + upper[i]) / 2.0;  // Midpoint of each class
        sum_fx += mid * freq[i];
        total_freq += freq[i];
    }

    return sum_fx / total_freq;
}


