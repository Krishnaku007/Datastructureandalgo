// Given a character array arr[] containing only lowercase English alphabets, the task is to print the maximum length of the subarray such that the first
//  and the last element of the sub-array are same.

//  Input: arr[] = {‘g’, ‘e’, ‘e’, ‘k’, ‘s’} 
// Output: 2 
// {‘e’, ‘e’} is the maximum length sub-array satisfying the given condition.
// Input: arr[] = {‘a’, ‘b’, ‘c’, ‘d’, ‘a’} 
// Output: 5 
// {‘a’, ‘b’, ‘c’, ‘d’, ‘a’} is the required sub-array 

// Approach: For every element of the array ch, store it’s first and 
// last occurrence. Then the maximum length of the sub-array that starts and ends 
// with the same element ch will be lastOccurrence(ch) – firstOccurrence(ch) + 1. The maximum of this value among all the elements is the required answer.
// Below is the implementation of the above approach: 

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
 
// Class that represents a single element
// of the given array and stores it's first
// and the last occurrence in the array
class Element
{
public:
    int firstOcc, lastOcc;
    Element();
    void updateOccurence(int);
};
 
Element::Element()
{
    firstOcc = lastOcc = -1;
}
 
// Function to update the occurrence
// of a particular character in the array
void Element::updateOccurence(int index)
{
    // If first occurrence is set to something
    // other than -1 then it doesn't need updating
    if (firstOcc == -1)
        firstOcc = index;
 
    // Last occurrence will be updated everytime
    // the character appears in the array
    lastOcc = index;
}
 
// Function to return the maximum length of the
// sub-array that starts and ends with the same element
int maxLenSubArr(string arr, int n)
{
    Element elements[26];
 
    for (int i = 0; i < n; i++)
    {
        int ch = arr[i] - 'a';
 
        // Update current character's occurrence
        elements[ch].updateOccurence(i);
    }
 
    int maxLen = 0;
    for (int i = 0; i < 26; i++)
    {
        // Length of the longest sub-array that starts
        // and ends with the same element
        int len = elements[i].lastOcc - 
                  elements[i].firstOcc + 1;
        maxLen = max(maxLen, len);
    }
 
    // Return the maximum length of
    // the required sub-array
    return maxLen;
}
 
// Driver Code
int main()
{
    string arr = "geeks";
    int n = arr.length();
 
    cout << maxLenSubArr(arr, n) << endl;
 
    return 0;
}

// Output: 
// 2

// Time Complexity: O(N) 
// Auxiliary Space: O(N)