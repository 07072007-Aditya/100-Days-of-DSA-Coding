/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for hash map (simple version using arrays)
#define MAX 1000

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    // Hash map using arrays
    int hash[MAX];
    
    // Initialize hash with -1 (means not seen)
    for (int i = 0; i < MAX; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum is zero, subarray from 0 to i
        if (sum == 0) {
            max_len = i + 1;
        }

        // Handle negative sums (shift index)
        int key = sum + MAX / 2;

        if (hash[key] != -1) {
            // Already seen → subarray found
            int length = i - hash[key];
            if (length > max_len)
                max_len = length;
        } else {
            // Store first occurrence
            hash[key] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest subarray with sum 0: %d", maxLen(arr, n));

    return 0;
}