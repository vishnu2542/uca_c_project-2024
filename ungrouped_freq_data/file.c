#include <stdio.h>
#include <stdlib.h>
#include "unfreqstats.h"

int main() {
    int n;

    // Get the number of observations from the user
    printf("Enter the number of observations: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the observations and frequencies arrays
    double *observations = (double *)malloc(n * sizeof(double));
    int *frequencies = (int *)malloc(n * sizeof(int));

    // Get the observations from the user
    printf("Enter the observations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &observations[i]);
    }

    // Get the frequencies from the user
    printf("Enter the corresponding frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &frequencies[i]);
    }

    // Calculate mean, median, and mode using the ungrouped frequency distribution library
    double calculated_mean = mean_freq(observations, frequencies, n);
    double calculated_median = median_freq(observations, frequencies, n);
    double calculated_mode = mode_freq(observations, frequencies, n);

    // Open a file to store the data in table form
    FILE *fptr = fopen("ungrouped_freq_data.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        free(observations);
        free(frequencies);
        return 1;
    }

    // Write the table header
    fprintf(fptr, "Observations\tFrequencies\n");
    fprintf(fptr, "------------\t-----------\n");

    // Write the observations and frequencies to the file
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "%.2f\t\t%d\n", observations[i], frequencies[i]);
    }

    // Write the calculated mean, median, and mode to the file
    fprintf(fptr, "\nCalculated Mean: %.2f\n", calculated_mean);
    fprintf(fptr, "Calculated Median: %.2f\n", calculated_median);
    fprintf(fptr, "Calculated Mode: %.2f\n", calculated_mode);

    // Close the file
    fclose(fptr);

    // Print a confirmation message
    printf("Data successfully stored in 'ungrouped_freq_data.txt'\n");

    // Free allocated memory
    free(observations);
    free(frequencies);

    return 0;
}
