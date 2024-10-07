#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Function declaration (implement this part)
void findCommonElements(const vector<vector<int>>& matrix, int n){
    unordered_map<int,int> mp;
    int r=n;
    int c=matrix[0].size();
    for(int j=0;j<c;j++){
        mp[matrix[0][j]]++;
    }
    for(int i=1;i<n;i++){
        unordered_map<int,int> mp2;
        for(int k=0;k<c;k++){
            mp2[matrix[i][k]]++;
        }

        for(auto &it:mp){
            if(mp2.find(it.first)!=mp2.end()){
                it.second=min(it.second,mp2[it.first]);
            }else{
                it.second=0;
            }
        }
    }
    for(auto &it: mp){
        while(it.second!=0){
            cout<<it.first<<" ";
            it.second--;
        }
    }
}

int main() {
    int n, m;

    // Input the number of rows and columns of the matrix
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

    // Call the findCommonElements function
    cout << "Distinct elements common to all rows: ";
    findCommonElements(matrix, n);

    return 0;
}
