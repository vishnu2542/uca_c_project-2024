// test_grouped_freqstats.c
#include <stdio.h>
#include "grouped_freqstats.h"

int main() {
    // Test Case: Sample class intervals and corresponding frequencies
    int n = 5;
    double lower[] = {0, 10, 20, 30, 40};  // Lower boundaries of class intervals
    double upper[] = {10, 20, 30, 40, 50};  // Upper boundaries of class intervals
    int frequencies[] = {5, 8, 15, 6, 6};   // Corresponding frequencies

    // Calculate and print the mean
    double calculated_mean = mean_grouped(lower, upper, frequencies, n);
    printf("Calculated Mean: %.2f\n", calculated_mean);

    // Calculate and print the median
    double calculated_median = median_grouped(lower, upper, frequencies, n);
    printf("Calculated Median: %.2f\n", calculated_median);

    // Calculate and print the mode
    double calculated_mode = mode_grouped(lower, upper, frequencies, n);
    printf("Calculated Mode: %.2f\n", calculated_mode);

    return 0;
}
