#include <iostream>
using namespace std;

int LCS(string s1,string s2){
    int m=s1.size();
    int n=s2.size();
    int dp[m+1][n+1]={};
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int a=LCS(s1,s2);
    cout<<a;
    return 0;
}