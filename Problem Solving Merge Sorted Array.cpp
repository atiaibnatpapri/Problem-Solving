/*
Problem: Merge Two Sorted Arrays

You are given two sorted integer arrays nums1 and nums2.

- nums1 has size (m + n), where the first m elements are valid and the last n elements are 0 (empty space).
- nums2 has size n and contains n valid elements.

Your task is to merge nums2 into nums1 so that nums1 becomes a single sorted array in non-decreasing order.

The final sorted array must be stored inside nums1.
*/

//SOLUTION

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};

    int m = 3;
    int n = 3;

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }

        k--;
    }

    while(j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    for(int x = 0; x < m+n; x++)
    {
        cout << nums1[x] << " ";
    }
}
