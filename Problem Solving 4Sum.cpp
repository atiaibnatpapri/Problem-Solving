#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    int nums[200]; // max size as per constraint
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums, nums + n); // sort the array

    for(int i = 0; i < n-3; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate i

        for(int j = i+1; j < n-2; j++) {
            if(j > i+1 && nums[j] == nums[j-1]) continue; // skip duplicate j

            int left = j+1;
            int right = n-1;

            while(left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if(sum == target) {
                    // print the quadruplet
                    cout << nums[i] << " " << nums[j] << " " << nums[left] << " " << nums[right] << endl;

                    // skip duplicates
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum < target) left++;
                else right--;
            }
        }
    }

    return 0;
}
