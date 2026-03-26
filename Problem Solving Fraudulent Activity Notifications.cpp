#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    int expenditure[100000]; // max size as per constraints
    for(int i = 0; i < n; i++) cin >> expenditure[i];

    int notifications = 0;

    int count[201] = {0}; // counting array for last d days

    // initialize count for first d days
    for(int i = 0; i < d; i++) count[expenditure[i]]++;

    // loop from day d to n-1
    for(int i = d; i < n; i++) {

        // find median
        int sum = 0;
        int median2 = 0; // double median
        if(d % 2 == 1) { // odd d
            int mid = d/2 + 1;
            for(int j = 0; j <= 200; j++) {
                sum += count[j];
                if(sum >= mid) {
                    median2 = 2*j; // multiply by 2 directly
                    break;
                }
            }
        } else { // even d
            int mid1 = d/2;
            int mid2 = d/2 + 1;
            int m1 = 0, m2 = 0;
            for(int j = 0; j <= 200; j++) {
                sum += count[j];
                if(sum >= mid1 && m1 == 0) m1 = j;
                if(sum >= mid2) {
                    m2 = j;
                    break;
                }
            }
            median2 = m1 + m2;
        }

        // check notification
        if(expenditure[i] >= median2) notifications++;

        // update count for sliding window
        count[expenditure[i-d]]--; // remove oldest
        count[expenditure[i]]++;   // add newest
    }

    cout << notifications << endl;
    return 0;
}
