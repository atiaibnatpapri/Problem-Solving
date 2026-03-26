
/*
Problem: Ball Sorting into Baskets (After Training)

There are n balls and m baskets in a row (numbered 1 to m).
Balls are numbered 1 to n and must be placed in order.

Valeric's scheme for each new ball:
1. Put it into the basket with the fewest balls.
2. If multiple baskets have the same minimum, choose the one closest to the middle (basket i minimizing |i - (m+1)/2| ).
3. If still multiple, choose the basket with the smallest number.

Input:
- First line: n m (number of balls, number of baskets)

Output:
- n lines: the basket number for each ball in order

Example:
Input:
4 3
Output:
2
1
3
2

Explanation:
- Ball 1: Basket 2 (middle)
- Ball 2: Basket 1 (tie: 0 balls, closest to middle)
- Ball 3: Basket 3
- Ball 4: Basket 2
*/

//SOLUTION

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int basket[100005] = {0}; // count of balls in each basket

    // Create order manually (middle first)
    int order[100005];
    int idx = 0;

    int mid = (m + 1) / 2;

    order[idx++] = mid;

    // go left and right from middle
    for(int d = 1; d < m; d++) {
        if(mid - d >= 1) order[idx++] = mid - d;
        if(mid + d <= m) order[idx++] = mid + d;
    }

    // Process each ball
    for(int i = 1; i <= n; i++) {
        int best = order[0];

        for(int j = 0; j < m; j++) {
            int b = order[j];

            if(basket[b] < basket[best]) {
                best = b;
            }
        }

        basket[best]++;
        cout << best << endl;
    }

    return 0;
}
