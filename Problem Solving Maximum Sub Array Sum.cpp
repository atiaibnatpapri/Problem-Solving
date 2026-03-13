#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long current_sum = a[0];
    long long maximum_sum = a[0];

    for(int i = 1; i < n; i++)
    {
        current_sum = max(a[i], current_sum + a[i]);

        maximum_sum = max(maximum_sum, current_sum);
    }

    cout << maximum_sum;

    return 0;
}
