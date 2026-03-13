#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    long long ticket[200000];

    for(int i=0;i<n;i++)
    cin>>ticket[i];

    // bubble sort
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(ticket[j]>ticket[j+1])
            {
                long long temp=ticket[j];
                ticket[j]=ticket[j+1];
                ticket[j+1]=temp;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        long long price;
        cin>>price;

        int pos=-1;

        for(int j=n-1;j>=0;j--)
        {
            if(ticket[j]!=-1 && ticket[j]<=price)
            {
                pos=j;
                break;
            }
        }

        if(pos==-1)
        cout<<-1<<endl;
        else
        {
            cout<<ticket[pos]<<endl;
            ticket[pos]=-1;
        }
    }
}
