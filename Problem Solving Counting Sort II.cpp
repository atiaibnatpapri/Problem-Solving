/*
Problem: You are given an unsorted list of integers. Your task is to sort them using the Counting Sort method and print the sorted array.

Definitions:
- Counting Sort: A non-comparison sorting algorithm. It works by counting the occurrences of each integer in the array and then reconstructing the sorted array from these counts.
- Frequency Array: An array where the index represents the integer and the value at that index represents how many times that integer occurs in the original array.

Task:
- Given an array arr[] of integers, count how many times each number occurs.
- Use these counts to reconstruct the sorted array in ascending order.
- Print the sorted array as a single line of space-separated integers.

Input:
- First line: integer n — the number of elements in arr.
- Second line: n integers — the elements of arr (0 <= arr[i] < 100).

Output:
- A single line with the n integers of arr in ascending order.

Example:

Input:
100
63 25 73 1 98 73 56 84 86 57 16 83 8 25 81 56 9 53 98 67 99 ...

Output:
1 1 3 3 6 8 9 9 10 12 13 16 16 18 20 21 21 22 23 24 25 25 25 ...

Explanation:
- First, count how many times each number occurs.
- Then, for each number from smallest to largest, print it as many times as it occurs.
- This produces the sorted array in ascending order.

Constraints:
- 1 <= n <= 10^6 (or as given)
- 0 <= arr[i] < 100

Note:
- Counting Sort is very efficient for small ranges of integers.
- The main idea is to avoid comparison-based sorting by using counting.
*/

//SOLUTION

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int freq[100] = {0};   // initialize frequency array

    // Count frequency of each number
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print sorted array using frequency array
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < freq[i]; j++) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
