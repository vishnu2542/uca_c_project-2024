// rawstats.c
#include "rawstats.h"
#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean
double mean(double arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Helper function for qsort
int compare(const void *a, const void *b) {
    double diff = (*(double*)a - *(double*)b);
    return (diff > 0) - (diff < 0); // Return -1, 0, or 1
}

// Function to calculate median
double median(double arr[], int n) {
    qsort(arr, n, sizeof(double), compare);
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

// Function to calculate mode
double mode(double arr[], int n) {
    int maxCount = 0;
    double modeValue = arr[0];
    
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            modeValue = arr[i];
        }
    }
    // If there's no repeating element, the array has no mode
    if (maxCount == 1) {
        printf("No mode for the data\n");
        return -1; // Or some error value
    }
    return modeValue;
}
