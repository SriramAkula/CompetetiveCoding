#include <iostream>
#include <vector>
using namespace std;

// Function declaration (implement this part)
void makeUpperTriangular(vector<vector<int>>& matrix, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                matrix[i][j]=0;
            }
        }
    }
}
void makeLowerTriangular(vector<vector<int>>& matrix, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                matrix[i][j]=0;
            }
        }
    }
}

int main() {
    int n;
    
    // Input the size of the matrix (nxn)
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;
    
    // Input the matrix
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Call the makeUpperTriangular function
    makeUpperTriangular(matrix, n);
    
    // Output the upper triangular matrix
    cout << "Upper triangular matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    makeLowerTriangular(matrix, n);
    cout << "Upper triangular matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
