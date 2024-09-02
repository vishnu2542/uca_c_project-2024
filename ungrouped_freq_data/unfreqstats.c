// freqstats.c
#include <stdio.h>
#include "unfreqstats.h"
#include <stdlib.h>

// Function to calculate mean for ungrouped frequency distribution
double mean_freq(double obs[], int freq[], int n) {
    double sum = 0.0;
    int total_freq = 0;

    for (int i = 0; i < n; i++) {
        sum += obs[i] * freq[i];
        total_freq += freq[i];
    }

    return sum / total_freq;
}


