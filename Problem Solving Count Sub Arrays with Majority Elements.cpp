/*
Problem: Count Subarrays Where Target is Majority

You are given an integer array nums and an integer target.

A subarray is a contiguous part of the array.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

Task:
Find and return the number of subarrays in which the given target element is the majority element.

Important:
- A subarray is valid if target appears more than (length of subarray / 2) times.
- If target does not exist in nums, the answer will be 0.
*/

//SOLUTION

#include <iostream>
using namespace std;

int main()
{
    int n,target;
    cin >> n;

    int nums[1005];

    for(int i=0;i<n;i++)
        cin >> nums[i];

    cin >> target;

    int ans = 0;

    for(int i=0;i<n;i++)
    {
        int count = 0;

        for(int j=i;j<n;j++)
        {
            if(nums[j] == target)
                count++;

            int length = j-i+1;

            if(count > length/2)
                ans++;
        }
    }

    cout << ans;
}
