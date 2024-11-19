#include <iostream>
using namespace std;

int main() {
    int wt[3]={3,1,1};
    int val[3]={40,50,20};
    int w=5;
    int dp[4][6];
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<4;i++){
        for(int j=1;j<6;j++){
            if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    cout<<dp[3][5];
    return 0;
}