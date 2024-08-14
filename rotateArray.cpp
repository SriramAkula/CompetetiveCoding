#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int k;
    cin >> k;
    
    // Adjust k to ensure it is within the bounds of the array
    k = k % n;

    int a1[n];
    
    // Copy the last k elements to the beginning of the new array
    for(int i = 0; i < k; i++) {
        a1[i] = arr[n - k + i];
    }
    
    // Copy the first n-k elements to the new array
    for(int i = 0; i < n - k; i++) {
        a1[k + i] = arr[i];
    }
    
    // Output the rotated array
    for(int i = 0; i < n; i++) {
        cout << a1[i] << " ";
    }
    
    return 0;
}
