#include <bits/stdc++.h>
using namespace std;

int knap(vector<int> wt,vector<int> v,int capacity){
    int m=wt.size();
    int n=capacity;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+v[i-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    int n,cap;
    cin>>n>>cap;
    vector<int> wt(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> v[i];  
    }
    int a=knap(wt,v,cap);
    cout<<a;

    return 0;
}