#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n) {
    sort(arr, arr + size);
    int l = 0;
    int r = 1;
    n = abs(n);

    while (l <= r and r < size) {
        int diff = arr[r] - arr[l];
        if (diff == n and l != r) {
            cout << "Pair Found: (" << arr[l] << ", " << arr[r] << ")";
            return true;
        }
        else if (diff > n) 
            l++;
        else 
            r++;
    }
    cout << "No such pair";
    return false;
}

int main() {
    int arr[] = { 1, 8, 30, 40, 100 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = -60;
    findPair(arr, size, n);
    cout << endl;
    n = 20;
    findPair(arr, size, n);
    return 0;
}
