#include <iostream>
#include <vector>
using namespace std;

// Function declaration (implement this part)
void spiralTraversal(vector<vector<int>>& matrix, int n, int m){

    int top=0;
    int left=0;
    int bottom=n-1;
    int right=m-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<matrix[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<matrix[i][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<matrix[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right){

            for(int i=bottom;i>=top;i--){
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }

    }
}

int main() {
    int n, m;
    
    // Input the size of the matrix (nxm)
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;
    
    // Input the matrix
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Call the spiralTraversal function
    cout << "Spiral traversal: ";
    spiralTraversal(matrix, n, m);
    
    return 0;
}
