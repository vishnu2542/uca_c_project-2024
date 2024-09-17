#include <stdio.h>
#include <stdlib.h>
#include "unfreqstats.h"

int main() {
    int n;

    // Ask the user for the number of observations
    printf("Enter the number of observations: ");
    while (scanf("%d", &n) != 1 || n <= 0) { // Check if input is a valid positive integer
        printf("Invalid entry. Please enter a valid positive number for the number of observations: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    // Dynamically allocate memory for observations and frequencies arrays
    double *obs = (double *)malloc(n * sizeof(double));
    int *freq = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (obs == NULL || freq == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the observations from the user with input validation
    printf("Enter the observations:\n");
    for (int i = 0; i < n; i++) {
        printf("Observation %d: ", i + 1);
        while (scanf("%lf", &obs[i]) != 1) { // Check if input is valid (floating-point number)
            printf("Invalid entry. Please enter a valid number for observation %d: ", i + 1);
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    // Get the frequencies from the user with input validation
    printf("Enter the frequencies corresponding to the observations:\n");
    for (int i = 0; i < n; i++) {
        printf("Frequency for observation %d: ", i + 1);
        while (scanf("%d", &freq[i]) != 1 || freq[i] <= 0) { // Check if input is valid (positive integer)
            printf("Invalid entry. Please enter a valid positive number for frequency %d: ", i + 1);
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    // Calculate and display the mean, median, and mode for the frequency distribution
    printf("Mean: %.2f\n", mean_freq(obs, freq, n));
    printf("Median: %.2f\n", median_freq(obs, freq, n));
    printf("Mode: %.2f\n", mode_freq(obs, freq, n));

    // Free the dynamically allocated memory
    free(obs);
    free(freq);

    return 0;
}
