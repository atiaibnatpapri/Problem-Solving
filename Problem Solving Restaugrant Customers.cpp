#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long arrival[200000];
    long long leave[200000];

    for(int i=0;i<n;i++)
    {
        cin >> arrival[i] >> leave[i];
    }

    int maximum = 0;

    for(int i=0;i<n;i++)
    {
        int count = 0;

        for(int j=0;j<n;j++)
        {
            if(arrival[j] <= arrival[i] && arrival[i] < leave[j])
            {
                count++;
            }
        }

        if(count > maximum)
        maximum = count;
    }

    cout << maximum;

    system("pause");


}
