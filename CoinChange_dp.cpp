#include <bits/stdc++.h>
using namespace std;

int main() {
    int coin[3]={2,5,7};
    int target=11;
    int n=sizeof(coin)/sizeof(coin[0]);
    int dp[n+1][target+1]={};
    for(int i=0;i<=target;i++){
        dp[0][i]=target+1;
    }
   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j>=coin[i-1]){
                dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][target]==target+1){
        cout<<-1;
    }else{
        cout<<dp[n][target];
    }
    return 0;
}