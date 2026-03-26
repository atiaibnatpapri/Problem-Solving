/*
Problem: You are given n coins, each with a positive integer value.

Task:
- Find the smallest positive sum that **cannot** be created using any subset of these coins.

Input:
- First line: integer n — the number of coins.
- Second line: n integers x1, x2, ..., xn — the value of each coin.

Output:
- Print a single integer: the smallest sum that cannot be made with any subset of the coins.

Example:

Input:
5
2 9 1 2 7

Output:
6

Explanation:
- Using subsets of coins you can make sums like 1, 2, 3, 4, 5.
- The smallest sum you **cannot** make is 6.

Constraints:
- 1 <= n <= 2 * 10^5
- 1 <= x_i <= 10^9
*/

//SOLUTION

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    sort(coins, coins + n); // small to large

    long long smallest = 1; // smallest sum which is not built yet

    for (int i = 0; i < n; i++) {
        if (coins[i] > smallest) {

            break;
        }
        smallest += coins[i]; //increase the range using coins
    }

    cout << smallest << endl;
    return 0;
}
