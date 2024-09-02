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

// Function to calculate median for ungrouped frequency distribution
double median_freq(double obs[], int freq[], int n) {
    // First, calculate the cumulative frequency
    int *cumulative_freq = (int *)malloc(n * sizeof(int));
    if (cumulative_freq == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    cumulative_freq[0] = freq[0];
    for (int i = 1; i < n; i++) {
        cumulative_freq[i] = cumulative_freq[i - 1] + freq[i];
    }

    // Find the median class
    int total_freq = cumulative_freq[n - 1];
    int median_pos = total_freq / 2;

    for (int i = 0; i < n; i++) {
        if (cumulative_freq[i] >= median_pos) {
            free(cumulative_freq);
            return obs[i];
        }
    }

    free(cumulative_freq);
    return -1; // Should not reach here
}


