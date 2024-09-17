#include <stdio.h>
#include <stdlib.h>
#include "grouped_freqstats.h"

int main() {
    int n;

    // Get the number of class intervals from the user with input validation for a positive integer
    printf("Enter the number of class intervals: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid entry. Please enter a valid positive integer for the number of class intervals: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    // Dynamically allocate memory for arrays
    double *lower = (double *)malloc(n * sizeof(double));
    double *upper = (double *)malloc(n * sizeof(double));
    int *frequencies = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (lower == NULL || upper == NULL || frequencies == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the class intervals and frequencies from the user with input validation
    for (int i = 0; i < n; i++) {
        printf("Enter lower boundary of class interval %d: ", i + 1);
        while (scanf("%lf", &lower[i]) != 1) {
            printf("Invalid entry. Please enter a valid number for the lower boundary of class interval %d: ", i + 1);
            while (getchar() != '\n'); // Clear the input buffer
        }

        printf("Enter upper boundary of class interval %d: ", i + 1);
        while (scanf("%lf", &upper[i]) != 1) {
            printf("Invalid entry. Please enter a valid number for the upper boundary of class interval %d: ", i + 1);
            while (getchar() != '\n'); // Clear the input buffer
        }

        printf("Enter frequency of class interval %d: ", i + 1);
        while (scanf("%d", &frequencies[i]) != 1 || frequencies[i] < 0) {
            printf("Invalid entry. Please enter a valid positive integer for the frequency of class interval %d: ", i + 1);
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    // Calculate and print the mean
    double calculated_mean = mean_grouped(lower, upper, frequencies, n);
    printf("\nCalculated Mean: %.2f\n", calculated_mean);

    // Calculate and print the median
    double calculated_median = median_grouped(lower, upper, frequencies, n);
    printf("Calculated Median: %.2f\n", calculated_median);
    
    // Calculate and print the mode
    double calculated_mode = mode_grouped(lower, upper, frequencies, n);
    printf("Calculated Mode: %.2f\n", calculated_mode);

    // Free allocated memory
    free(lower);
    free(upper);
    free(frequencies);

    return 0;
}
