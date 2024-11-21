#include <iostream>
using namespace std;



int main() {
    string a;
    string b;
    cin>>a;
    cin>>b;
    int m=a.length();
    int n=b.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;

            }else{
                if(a[i]==b[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    cout<<dp[m][n];
    return 0;
}