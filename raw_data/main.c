#include <stdio.h>
#include <stdlib.h>
#include "rawstats.h"

int main() {
    int n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of observations: ");
    while (scanf("%d", &n) != 1 || n <= 0) { // Check if the input is a valid positive integer
        printf("Invalid entry. Please enter a valid positive integer for the number of observations: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    // Dynamically allocate memory for the array based on the user's input
    double *data = (double *)malloc(n * sizeof(double));

    // Check if memory allocation was successful
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the array elements from the user
    printf("Enter the data:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);

        // Use scanf and check if the input is valid (i.e., a valid number)
        while (scanf("%lf", &data[i]) != 1) {
            // If input is invalid, clear the input buffer and prompt the user again
            printf("Invalid entry. Please enter a valid number for element %d: ", i + 1);
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    // Calculate and display the mean, median, and mode
    printf("Mean: %.2f\n", mean(data, n));
    printf("Median: %.2f\n", median(data, n));

    double modeResult = mode(data, n);
    if (modeResult != -1) {
        printf("Mode: %.2f\n", modeResult);
    } else {
        printf("No mode found.\n");
    }

    // Free the dynamically allocated memory
    free(data);

    return 0;
}
