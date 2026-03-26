/*
Problem: Apartment Assignment
There are n applicants and m free apartments. Your task is to distribute the apartments
so that as many applicants as possible will get an apartment.

- Each applicant has a desired apartment size, and they will accept any apartment whose
  size is close enough to the desired size (within k difference).

Input:
- First line: n m k
- Second line: n integers: desired apartment sizes of applicants
- Third line: m integers: sizes of apartments

Output:
- One integer: maximum number of applicants who can get an apartment

Example:
Input:
4 3 5
60 45 80 60
30 60 75
Output:
2

Constraints:
1 <= n, m <= 2*10^5
0 <= k <= 10^9
1 <= ai, bi <= 10^9

*/

//SOLUTION


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a[n], b[m];

    //applicants

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    //apartments

    for(int j=0; j<m; j++){
        cin>>b[j];
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for (int i=0;i<n;i++)
        {
            for(int j=0; j<m; j++){
                if(b[i]>=a[i]-k && b[j]<=a[i]+k){
                    count++;


                    //remove used apartment
                    for(int x=j; x<m-1; x++)
                    {
                        b[x]=b[x+1];
                    }
                    m--;
                    break;
                }
            }
        }
        cout<<count;
        return 0;
    }
}

