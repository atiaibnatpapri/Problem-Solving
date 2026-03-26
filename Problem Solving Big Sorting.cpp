/*
Problem: You are given an array of numeric strings. Each string represents a positive integer with an arbitrary number of digits.

Task:
- Sort the array in ascending order according to the **integer values** of the strings, not lexicographically.

Input:
- The first line contains an integer n — the number of strings.
- The next n lines each contain a numeric string.

Output:
- Print the sorted array of strings, one per line.

Example:

Input:
6
31415926535897932384626433832795
1
3
10
3
5

Output:
1
3
3
5
10
31415926535897932384626433832795

Explanation:
- Compare the strings based on their numeric values, not as plain text.
- '10' comes after '5', even though '1' < '5' lexicographically.

Constraints:
- Each string represents a positive integer without leading zeros.
- The total number of digits across all strings is within reasonable limits for processing.
*/

//SOLUTION

#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
