/*
Problem: Given a playlist of a radio station with n songs, each song has an ID number.

Task:
- Find the length of the longest contiguous sequence of songs where all songs are unique.

Input:
- First line: integer n — number of songs.
- Second line: n integers k1, k2, ..., kn — the ID of each song.

Output:
- Print a single integer: the length of the longest contiguous unique song sequence.

Example:

Input:
8
1 2 1 3 2 7 4 2

Output:
5

Explanation:
- The longest sequence of unique songs is [1, 3, 2, 7, 4], which has length 5.

Constraints:
- 1 <= n <= 2 * 10^5
- 1 <= k_i <= 10^9
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter number of songs: ";
    cin >> n;

    int arr[n];
    cout << "Enter song IDs: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<int> s;  // unique elements track

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++) {

        // duplicate remove
        while (s.find(arr[right]) != s.end()) {
            s.erase(arr[left]);
            left++;
        }

        // new element insert
        s.insert(arr[right]);

        // length update
        int len = right - left + 1;
        if (len > maxLen)
            maxLen = len;
    }

    cout << "Longest unique sequence length: " << maxLen << endl;

    return 0;
}
