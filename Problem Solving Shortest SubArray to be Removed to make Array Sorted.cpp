#include <iostream>
#include <vector>
using namespace std;

int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();

    // find non-decreasing prefix
    int left = 0;
    while (left + 1 < n && arr[left] <= arr[left + 1]) left++;

    // Already sorted
    if (left == n - 1) return 0;

    // find non-decreasing suffix
    int right = n - 1;
    while (right - 1 >= 0 && arr[right - 1] <= arr[right]) right--;

    // initial answer: remove left only or right only
    int ans = min(n - left - 1, right);

    // merge prefix and suffix
    int i = 0, j = right;
    while (i <= left && j < n) {
        if (arr[i] <= arr[j]) {
            ans = min(ans, j - i - 1);
            i++;
        } else {
            j++;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1,2,3,10,4,2,3,5};
    cout << findLengthOfShortestSubarray(arr) << endl;
    return 0;
}
