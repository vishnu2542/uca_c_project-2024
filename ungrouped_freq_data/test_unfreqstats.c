#include <stdio.h>
#include <stdlib.h>
#include "unfreqstats.h"

int main() {
    // Test Case: Sample observations and corresponding frequencies
    int n = 5;
    double observations[] = {10, 20, 30, 40, 50};  // Observation values
    int frequencies[] = {2, 3, 5, 2, 1};           // Corresponding frequencies

    // Calculate and print the mean
    double calculated_mean = mean_freq(observations, frequencies, n);
    printf("Calculated Mean: %.2f\n", calculated_mean);

    // Calculate and print the median
    double calculated_median = median_freq(observations, frequencies, n);
    printf("Calculated Median: %.2f\n", calculated_median);

    // Calculate and print the mode
    double calculated_mode = mode_freq(observations, frequencies, n);
    printf("Calculated Mode: %.2f\n", calculated_mode);

    return 0;
}
