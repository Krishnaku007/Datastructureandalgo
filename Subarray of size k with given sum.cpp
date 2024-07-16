// Given an array arr[], an integer K and a Sum. 
// The task is to check if there exists any subarray with K elements whose sum is equal to the given sum. If any of the subarray with size K has the sum equal 
// to the given sum then print YES otherwise print NO.

// Input: arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}
//         k = 4, sum = 18
// Output: YES
// Subarray = {4, 2, 10, 2}

// Input: arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}
//         k = 3, sum = 6
// Output: YES

// CPP program to check if any Subarray of size 
// K has a given Sum
#include <iostream>
using namespace std;
 
// Function to check if any Subarray of size K
// has a  given Sum
bool checkSubarraySum(int arr[], int n,
                      int k, int sum)
{
    // Consider all blocks starting with i.
    for (int i = 0; i < n - k + 1; i++) {
 
        int current_sum = 0;
 
        // Consider each subarray of size k
        for (int j = 0; j < k; j++)
            current_sum = current_sum + arr[i + j];
 
        if (current_sum == sum) 
            return true;        
    }
    return false;
}
 
// Driver code
int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int sum = 18;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    if (checkSubarraySum(arr, n, k, sum))
        cout << "YES";
    else
        cout << "NO";
 
    return 0;
}

// Output
// YES

// Time Complexity: O(n * k)