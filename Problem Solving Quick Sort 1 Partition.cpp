#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];  // max size 100
    for(int i = 0; i < n; i++) cin >> arr[i];

    int pivot = arr[0];

    int left[100], right[100];  // arrays to store elements <pivot and >pivot
    int leftSize = 0, rightSize = 0;

    // Partitioning
    for(int i = 1; i < n; i++) {
        if(arr[i] < pivot) {
            left[leftSize++] = arr[i];
        } else {
            right[rightSize++] = arr[i];
        }
    }

    // Output: left elements
    for(int i = 0; i < leftSize; i++) cout << left[i] << " ";

    // pivot
    cout << pivot << " ";

    // right elements
    for(int i = 0; i < rightSize; i++) cout << right[i] << " ";

    cout << endl;
    return 0;
}
