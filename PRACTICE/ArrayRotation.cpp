#include <iostream>
#include <vector>
using namespace std;

// Function declaration (implement this part)
void reverse(vector<int> &arr,int st,int end){
    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
}
void rotateArray(vector<int>& arr, int d){
    int n=arr.size();
    d=d%n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);

}

// Main driver function
int main() {
    int n, d;
    
    // Input the size of the array and the number of rotations
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter the number of positions to rotate: ";
    cin >> d;
    
    // Input the array
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call the rotateArray function
    rotateArray(arr, d);
    
    // Output the rotated array
    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    return 0;
}
