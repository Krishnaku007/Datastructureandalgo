// Given an array of both positive and negative integers and a number K., The task is to check if any subarray with product K is present in the array or not.

// Input: arr[] = {-2, -1, 3, -4, 5}, K = 2
// Output: YES

// Input: arr[] = {3, -1, -1, -1, 5}, K = 3
// Output: YES

#include <bits/stdc++.h>
using namespace std;

// Function to check if there exists a subarray with a product equal to k
bool hasSubarrayWithProduct(int* arr, int n, int k) {
    // Iterate over all possible starting points of subarrays
    for (int start = 0; start < n; ++start) {
        int product = 1; // Initialize the product for the current subarray
        // Iterate over all possible end points for subarrays starting at 'start'
        for (int end = start; end < n; ++end) {
            product *= arr[end]; // Update the product for the current subarray
            // Check if the current subarray product is equal to k
            if (product == k) {
                return true; // Return true if such subarray is found
            }
        }
    }
    return false; // Return false if no subarray with product k is found
}

int main() {
    int arr[] = {1, 2, -5, -4}; // Input array
    int product = -10; // Target product value
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Check if there is a subarray with the given product and print the result
    if (hasSubarrayWithProduct(arr, n, product)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0; // Exit the program
}

// Output
// YES

// Time Complexity: O(n2)
// Auxiliary Space: O(1)