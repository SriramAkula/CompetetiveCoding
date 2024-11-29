#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int ncr(int n,int r){
    if(r>n) return 0;
    int dp[n+1][r+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,r);j++){
            if(j==0||j==i){
                dp[i][j]=1;
            }else{
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
            }
        }
    }
    return dp[n][r];
}

int main() {
    int n,r;
    cin>>n>>r;
    int a=ncr(n,r);
    cout<<a;
    return 0;
}