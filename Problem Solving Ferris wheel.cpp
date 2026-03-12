#include <iostream>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    long long weights[2000];
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int gondolas = 0;

    for (int i = 0; i < n; i++) {
        if (weights[i] == 0) continue;

        long long w1 = weights[i];
        weights[i] = 0;

        for (int j = i+1; j < n; j++) {
            if (weights[j] != 0 && w1 + weights[j] <= x) {
                weights[j] = 0;
                break;
            }
        }

        gondolas++;
    }

    cout << gondolas << endl;
    return 0;
}
