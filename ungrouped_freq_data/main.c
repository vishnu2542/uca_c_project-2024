// test_freqstats.c
#include <stdio.h>
#include <stdlib.h>
#include "unfreqstats.h"

int main() {
    int n;

    // Ask the user for the number of observations
    printf("Enter the number of observations: ");
    scanf("%d", &n);

    // Dynamically allocate memory for observations and frequencies arrays
    double *obs = (double *)malloc(n * sizeof(double));
    int *freq = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (obs == NULL || freq == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the observations from the user
    printf("Enter the observations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &obs[i]);
    }

    // Get the frequencies from the user
    printf("Enter the frequencies corresponding to the observations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
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
