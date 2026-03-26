/*
Problem: Maximum Subarray Sum (Kadane's Algorithm)
Given an array of n integers, find the maximum sum of values in a contiguous, nonempty subarray.

Input:
- First line: n (size of array)
- Second line: n integers x1, x2, ..., xn

Output:
- One integer: maximum sum of a contiguous subarray

Example:
Input:
8
-1 3 -2 5 3 -5 2 2
Output:
9

Constraints:
1 <= n <= 2*10^5
-10^9 <= xi <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long current_sum = a[0];
    long long maximum_sum = a[0];

    for(int i = 1; i < n; i++)
    {
        current_sum = max(a[i], current_sum + a[i]);

        maximum_sum = max(maximum_sum, current_sum);
    }

    cout << maximum_sum;

    return 0;
}
