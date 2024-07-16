// Given an array of N numbers where a subarray is 
// sorted in descending order and rest of the numbers in the array are in ascending order. The task is to sort an array
//  where a subarray of a sorted array is in reversed order.

//  Input: 2 5 65 55 50 70 90 
// Output: 2 5 50 55 65 70 90 
// The subarray from 2nd index to 4th index is in reverse order. 
// So the subarray is reversed, and the sorted array is printed. 

// Input: 1 7 6 5 4 3 2 8 
// Output: 1 2 3 4 5 6 7 8

// C++ program to sort an array where
// a subarray of a sorted array
// is in reversed order
#include <bits/stdc++.h>
using namespace std;
 
// Function to print the sorted array
// by reversing the subarray
void printSorted(int a[], int n)
{
    int front = -1, back = -1;
 
    // find the starting index of the
    // reversed subarray
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            front = i - 1;
            break;
        }
    }
 
    // find the ending index of the
    // reversed subarray
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            back = i + 1;
            break;
        }
    }
 
    // if no reversed subarray is present
    if (front == -1 and back == -1) {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        return;
    }
 
    // swap the reversed subarray
    while (front <= back) {
 
        // swaps the front and back element
        // using c++ STL
        swap(a[front], a[back]);
 
        // move the pointers one step
        // ahead and one step back
        front++;
        back--;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
 
// Driver Code
int main()
{
    int a[] = { 1, 7, 6, 5, 4, 3, 2, 8 };
    int n = sizeof(a) / sizeof(a[0]);
    printSorted(a, n);
    return 0;
}

// Output
// 1 2 3 4 5 6 7 8

// Time Complexity: O(n)

// Auxiliary Space: O(1)