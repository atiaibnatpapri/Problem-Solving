#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000];
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long shifts = 0;  // use long long in case n is large

    // Insertion Sort with shift counting
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to the right
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // shift
            shifts++;             // count shift
            j--;
        }

        arr[j + 1] = key;  // insert key in correct place
    }

    cout << shifts << endl;

    return 0;
}
