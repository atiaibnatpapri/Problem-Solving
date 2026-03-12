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

