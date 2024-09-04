#include <stdio.h>
#include <stdlib.h>
#include "rawstats.h"

int main() {
    int n = 0;
    double *data = NULL;
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

    // Count the number of  lines in the file
    while (fgets(buffer, sizeof(buffer), fptr)) {
        if (buffer[0] == '\n') break; // Stop counting if a blank line is encountered
        n++;
    }

    // Allocate memory based on the number of data points
    data = (double *)malloc(n * sizeof(double));

    // Rewind the file to start reading the actual data
    rewind(fptr);

    // Skip the first two lines of the header again
    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);

    // Read the data points from the file
    for (int i = 0; i < n; i++) {
        fscanf(fptr, "%lf\n", &data[i]);
    }

    // Close the file after reading
    fclose(fptr);

    // Calculate the mean, median, and mode
    double calculated_mean = mean(data, n);
    double calculated_median = median(data, n);
    double calculated_mode = mode(data, n);

    // Print the calculated values
    printf("Calculated Mean: %.2f\n", calculated_mean);
    printf("Calculated Median: %.2f\n", calculated_median);
    printf("Calculated Mode: %.2f\n", calculated_mode);

    // Free allocated memory
    free(data);

    return 0;
}
