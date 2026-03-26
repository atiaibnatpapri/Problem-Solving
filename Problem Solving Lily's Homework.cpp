/*
Problem: George wants to help Lily finish her homework faster. Her homework involves making an array "beautiful".

Definitions:
- An array is "beautiful" if the sum of absolute differences between consecutive elements is minimized.
- You can swap any two elements of the array any number of times.

Task:
- Given an array of distinct integers, determine the minimum number of swaps required to make it beautiful.

Input:
- First line: integer n — the number of elements in the array.
- Second line: n space-separated integers — the elements of the array.

Output:
- Print a single integer: the minimum number of swaps required to make the array beautiful.

Example:

Input:
4
2 5 3 1

Output:
2

Explanation:
- One way to make the array beautiful is to sort it in ascending order: [1,2,3,5]
- Minimum swaps:
    Swap 2 with 1: [1,5,3,2]
    Swap 5 with 2: [1,2,3,5]
- Total swaps = 2
*/

//SOLUTION

#include <iostream>
using namespace std;

// Function to sort array in ascending order (bubble sort)

void sortAscending(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {

                // Swap arr[j] and arr[j+1]

                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to sort array in descending order (bubble sort)

void sortDescending(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] < arr[j+1]) {

                // Swap arr[j] and arr[j+1]

                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to count minimum swaps to convert 'arr' into 'target'

int countSwaps(int arr[], int target[], int n) {
    int swaps = 0;
    bool visited[100];  // max 100 elements, adjust if needed
    for(int i = 0; i < n; i++) visited[i] = false;

    for(int i = 0; i < n; i++) {
        if(visited[i] || arr[i] == target[i]) continue;

        int cycle_size = 0;
        int j = i;

        while(!visited[j]) {
            visited[j] = true;

            // find index of arr[j] in target

            int k;
            for(k = 0; k < n; k++) {
                if(target[k] == arr[j]) break;
            }

            j = k;  // move to the correct index
            cycle_size++;
        }

        if(cycle_size > 0) swaps += (cycle_size - 1);
    }

    return swaps;
}

int main() {
    int n;
    cin >> n;

    int arr[100];   // original array
    int asc[100];   // ascending sorted array
    int desc[100];  // descending sorted array

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        asc[i] = arr[i];
        desc[i] = arr[i];
    }

    // Sort arrays
    sortAscending(asc, n);
    sortDescending(desc, n);

    // Count minimum swaps for both ascending and descending
    int swapsAsc = countSwaps(arr, asc, n);
    int swapsDesc = countSwaps(arr, desc, n);

    // Print the minimum swaps
    cout << (swapsAsc < swapsDesc ? swapsAsc : swapsDesc) << endl;

    return 0;
}
