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

// Function to calculate median for grouped frequency distribution
double median_grouped(double lower[], double upper[], int freq[], int n) {
    int total_freq = 0;
    int cumulative_freq = 0;
    double median_class_lower_bound = 0;
    double median_class_width = 0;
    int median_class_index = 0;

    // Calculate total frequency
    for (int i = 0; i < n; i++) {
        total_freq += freq[i];
    }

    int median_pos = (total_freq + 1) / 2;  // Position of the median

    // Find the median class
    for (int i = 0; i < n; i++) {
        cumulative_freq += freq[i];
        if (cumulative_freq >= median_pos) {
            median_class_lower_bound = lower[i];
            median_class_width = upper[i] - lower[i];
            median_class_index = i;
            break;
        }
    }

    int cumulative_freq_before = cumulative_freq - freq[median_class_index];

    // Apply median formula
    return median_class_lower_bound + ((median_pos - cumulative_freq_before) / (double)freq[median_class_index]) * median_class_width;
}

