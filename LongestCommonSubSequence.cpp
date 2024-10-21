#include <iostream>
using namespace std;

int main() {
    string str1="abcdaf";
    string str2="acbcf";
    int m=str1.length();
    int n=str2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else{

                if(str1[i]==str2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }

        }
    }
    cout<<dp[m][n];
    string s="";
    for(int i=m;i>=0;i--){
        for(int j=n;j>=0;j--){
            if(str1[i]==str2[j]){
                s=str1[i]+s;
                i--;
                j--;
            }else{
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                if(up>left){
                    i--;
                    // if(str[i]==str[j]){
                    //     s=str[i]+s;
                    // }
                }else{
                    j--;
                    // if(str[i]==str[j]){
                    //     s=str[i]+s;
                    // }
                }
            }
            if(str1[i]==str2[j]){
                s=str1[i]+s;
            }
        }
    }
    cout<<s;
    return 0;
}