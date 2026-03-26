/*
Problem: Count Distinct Numbers
You are given a list of n integers. Your task is to calculate the number of distinct values in the list.

Input:
- The first line contains an integer n: the number of values.
- The second line contains n integers x1, x2, ..., xn.

Output:
- Print one integer: the number of distinct values.

Example:
Input:
5
2 3 2 2 3
Output:
2

Constraints:
1 <= n <= 2*10^5
1 <= xi <= 10^9
*/

//SOLUTION

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];

    //array input

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    //Bubble sort

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if (a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    //count distinct numbers

    int count=1;
    for(int i=1; i<n; i++){
        if(a[i]!=a[i-1]){
            count++;
        }
    }
    cout<<count++;
    return 0;

}
