#include <stdio.h>
#include <stdlib.h>
#include "rawstats.h"

int main() {
    int n;

    // Get the number of observations from the user
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the data array
    double *data = (double *)malloc(n * sizeof(double));

    // Get the raw data from the user
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }

    // Calculate mean, median, and mode using the rawstats library
    double calculated_mean = mean(data, n);
    double calculated_median = median(data, n);
    double calculated_mode = mode(data, n);

    // Open a file to store the data in table form
    FILE *fptr = fopen("raw_data.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        free(data);
        return 1;
    }

    // Write the table header
    fprintf(fptr, "Data Points\n");
    fprintf(fptr, "-----------\n");

    // Write the raw data to the file
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "%.2f\n", data[i]);
    }

    // Write the calculated mean, median, and mode to the file
    fprintf(fptr, "\nCalculated Mean: %.2f\n", calculated_mean);
    fprintf(fptr, "Calculated Median: %.2f\n", calculated_median);
    fprintf(fptr, "Calculated Mode: %.2f\n", calculated_mode);

    // Close the file
    fclose(fptr);

    // Print a confirmation message
    printf("Data successfully stored in 'raw_data.txt'\n");

    // Free allocated memory
    free(data);

    return 0;
}
