#include <iostream>
using namespace std;

int main()
{
    int n;
    long long l;
    cin >> n >> l;

    long long a[1005];

    for(int i=0;i<n;i++)
        cin >> a[i];

    // selection sort
    for(int i=0;i<n-1;i++)
    {
        int minIndex = i;

        for(int j=i+1;j<n;j++)
        {
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        long long temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    double d = 0;

    // start gap
    if((double)a[0] > d)
        d = (double)a[0];

    // end gap
    if((double)(l-a[n-1]) > d)
        d = (double)(l-a[n-1]);

    // middle gap
    for(int i=0;i<n-1;i++)
    {
        double gap = (a[i+1]-a[i])/2.0;

        if(gap > d)
            d = gap;
    }

    cout << d;
}
