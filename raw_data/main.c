#include <stdio.h>
#include <stdlib.h>
#include "rawstats.h"

int main() {
    int n;
    
    // Ask the user for the number of elements in the array
    printf("Enter the number of observations: ");
    scanf("%d", &n);

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
        scanf("%lf", &data[i]);
    }

    // Calculate and display the mean, median, and mode
    printf("Mean: %.2f\n", mean(data, n));
    printf("Median: %.2f\n", median(data, n));
    double modeResult = mode(data, n);
    if (modeResult != -1) {
        printf("Mode: %.2f\n", modeResult);
    }

    // Free the dynamically allocated memory
    free(data);

    return 0;
}
