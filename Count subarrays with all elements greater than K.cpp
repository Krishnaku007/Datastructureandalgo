// Given an array of N integers and a number K, the task is to find the number of subarrays 
// such that all elements are greater than K in it. 

// Input: a[] = {3, 4, 5, 6, 7, 2, 10, 11}, K = 5 
// Output: 6 
// The possible subarrays are {6}, {7}, {6, 7}, {10}, {11} and {10, 11}.

// Input: a[] = {8, 25, 10, 19, 19, 18, 20, 11, 18}, K = 13 
// Output: 12 

// Approach: The idea is to start traversing the array using a counter. 
// If the current element is greater than the given value X,
// increment the counter otherwise add counter*(counter+1)/2 to the number of subarrays and reinitialize counter to 0

// C++ program to print the number of subarrays such
// that all elements are greater than K
#include <bits/stdc++.h>
using namespace std;
 
// Function to count number of subarrays
int countSubarrays(int a[], int n, int x)
{
    int count = 0;
 
    int number = 0;
 
    // Iterate in the array
    for (int i = 0; i < n; i++) {
 
        // check if array element
        // greater than X or not
        if (a[i] > x) {
            count += 1;
        }
        else {
 
            number += (count) * (count + 1) / 2;
            count = 0;
        }
    }
 
    // After iteration complete
    // check for the last set of subarrays
    if (count)
        number += (count) * (count + 1) / 2;
 
    return number;
}
 
// Driver Code
int main()
{
    int a[] = { 3, 4, 5, 6, 7, 2, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
 
    cout << countSubarrays(a, n, k);
 
    return 0;
}

// Output
// 6

// Complexity Analysis:

// Time Complexity: O(N) 
// Auxiliary Space: O(1)