#include <stdio.h>
#include <stdlib.h>
#include "grouped_freqstats.h"

int main() {
    int n = 0;
    double *lower = NULL;
    double *upper = NULL;
    int *frequencies = NULL;
    char buffer[100];

    // Open the file for reading
    FILE *fptr = fopen("read.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Skip the first two lines of the header
    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);

    // Count the number of lines (which corresponds to the number of classes)
    while (fgets(buffer, sizeof(buffer), fptr)) {
        if (buffer[0] == '\n') break; // Stop counting if a blank line is encountered
        n++;
    }

    // Allocate memory based on the number of classes
    lower = (double *)malloc(n * sizeof(double));
    upper = (double *)malloc(n * sizeof(double));
    frequencies = (int *)malloc(n * sizeof(int));

    // Rewind the file to start reading the actual data
    rewind(fptr);

    // Skip the first two lines of the header again
    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);

    // Read the class intervals and frequencies from the file
    for (int i = 0; i < n; i++) {
        fscanf(fptr, "[%lf, %lf)\t%d\n", &lower[i], &upper[i], &frequencies[i]);
    }

    // Close the file after reading
    fclose(fptr);

    // Calculate the mean, median, and mode
    double calculated_mean = mean_grouped(lower, upper, frequencies, n);
    double calculated_median = median_grouped(lower, upper, frequencies, n);
    double calculated_mode = mode_grouped(lower, upper, frequencies, n);

    // Print the calculated values
    printf("Calculated Mean: %.2f\n", calculated_mean);
    printf("Calculated Median: %.2f\n", calculated_median);
    printf("Calculated Mode: %.2f\n", calculated_mode);

    // Free allocated memory
    free(lower);
    free(upper);
    free(frequencies);

    return 0;
}
