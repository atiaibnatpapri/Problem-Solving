#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long start[200000], end[200000];

    for(int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];
    }

    // Bubble sort according to end time

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(end[j] > end[j+1]) {

                // swap end times

                long long temp = end[j];
                end[j] = end[j+1];
                end[j+1] = temp;

                // swap corresponding start times

                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }

    long long last_end = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(start[i] >= last_end) {
            count++;
            last_end = end[i];
        }
    }

    cout << count;
}
