// Stable
// Divide and Conquer
// O(n) auxiliary space

// Tim-sort - Merge Sort + Insertion sort

#include <iostream>
#include <algorithm> // Include the necessary header for std::sort
using namespace std;

// Merges and sorts two arrays into a new array
void merge(int a[], int b[], int m, int n) {
    int c[m + n];
    for (int i = 0; i < m; i++) {
        c[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        c[m + i] = b[i];
    }
    sort(c, c + m + n);
    
    cout << "Merged array (merge function): ";
    for (int i = 0; i < m + n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

// Merges and sorts two arrays in a single pass and prints the result
void merge1(int a[], int b[], int m, int n) {
    int i = 0, j = 0;
    cout << "Merged array (merge1 function): ";
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            cout << a[i] << " ";
            i++;
        } else {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < m) {
        cout << a[i] << " ";
        i++;
    }
    while (j < n) {
        cout << b[j] << " ";
        j++;
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // Testing merge function
    merge(arr1, arr2, m, n);

    // Testing merge1 function
    merge1(arr1, arr2, m, n);

    return 0;
}
