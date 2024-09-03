#include <stdio.h>
#include <stdlib.h>
#include "grouped_freqstats.h"

int main() {
    int n;
    
    // Get the number of classes from the user
    printf("Enter the number of class intervals: ");
    scanf("%d", &n);

    // Dynamically allocate memory for arrays
    double *lower = (double *)malloc(n * sizeof(double));
    double *upper = (double *)malloc(n * sizeof(double));
    int *frequencies = (int *)malloc(n * sizeof(int));

    // Get the class intervals and frequencies from the user
    for (int i = 0; i < n; i++) {
        printf("Enter lower boundary of class interval %d: ", i + 1);
        scanf("%lf", &lower[i]);
        printf("Enter upper boundary of class interval %d: ", i + 1);
        scanf("%lf", &upper[i]);
        printf("Enter frequency of class interval %d: ", i + 1);
        scanf("%d", &frequencies[i]);
    }

    // Calculate and print the mean
    double calculated_mean = mean_grouped(lower, upper, frequencies, n);
    printf("\nCalculated Mean: %.2f\n", calculated_mean);

    // Calculate and print the median
    double calculated_median = median_grouped(lower, upper, frequencies, n);
    printf("Calculated Median: %.2f\n", calculated_median);

    // Free allocated memory
    free(lower);
    free(upper);
    free(frequencies);

    return 0;
}
