#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int lomutoPartition(int arr[], int l, int h) {
    int pivot = arr[h]; // Pivot
    int i = l - 1; // Index of smaller element

    for (int j = l; j <= h - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

// Function to implement quicksort using Lomuto partition
void qSort(int arr[], int l, int h) {
    if (l < h) {
        int p = lomutoPartition(arr, l, h);
        qSort(arr, l, p - 1); // Recursively sort elements before partition
        qSort(arr, p + 1, h); // Recursively sort elements after partition
    }
}



int main() {
    int T;
    cout<<"No Of Test cases: ";
    cin>>T;
    while(T--){
        int n;
        cout<<"Size Of the Array: ";
        cin>>n;
        int arr[n];
        cout<<"Enter Array Elements: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int c;
        cout<<"Enter 1 for Quick Sort\n";
        cout<<"Enter 2 for Merge Sort\n";
    
        cin>>c;
        switch(c){
            case 1:
                qSort(arr,0,n);
                printArray(arr,n);
                break;
            case 2:
                // mSort(arr,0,n);
                printArray(arr,n);
                break;
            default:
                cout<<"Please enter valid case.";
        }
    }
    return 0;
}