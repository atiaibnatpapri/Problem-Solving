#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000];   // adjust size if needed
    for(int i = 0; i < n; i++) cin >> arr[i];

    int freq[100] = {0};  // initialize all to 0

    // Count frequencies
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print frequency array
    for(int i = 0; i < 100; i++) {
        cout << freq[i] << " ";
    }
    cout << endl;

    return 0;
}
