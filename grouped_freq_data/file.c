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

    // Calculate the mean, median, and mode
    double calculated_mean = mean_grouped(lower, upper, frequencies, n);
    double calculated_median = median_grouped(lower, upper, frequencies, n);
    double calculated_mode = mode_grouped(lower, upper, frequencies, n);

    // Open a file to store the data in table form
    FILE *fptr = fopen("grouped_freq_data.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        free(lower);
        free(upper);
        free(frequencies);
        return 1;
    }

    // Write the table header
    fprintf(fptr, "Class Interval\tFrequency\n");
    fprintf(fptr, "--------------\t---------\n");

    // Write the class intervals and frequencies to the file
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "[%.2f, %.2f)\t%d\n", lower[i], upper[i], frequencies[i]);
    }

    // Write the calculated mean, median, and mode to the file
    fprintf(fptr, "\nCalculated Mean: %.2f\n", calculated_mean);
    fprintf(fptr, "Calculated Median: %.2f\n", calculated_median);
    fprintf(fptr, "Calculated Mode: %.2f\n", calculated_mode);

    // Close the file
    fclose(fptr);

    // Print a confirmation message
    printf("Data successfully stored in 'grouped_freq_data.txt'\n");

    // Free allocated memory
    free(lower);
    free(upper);
    free(frequencies);

    return 0;
}
