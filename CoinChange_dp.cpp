#include <bits/stdc++.h>
using namespace std;
int f(int ind,int target,vector<int> &num){
    if(ind==0){
        if(target%num[ind]==0){
            return target/num[ind];
        }else{
            return 1e9;
        }
    }
    int notTake=0+f(ind-1,target,num);
    int take=INT_MAX;
    if(num[ind]<=target) take=1+f(ind,target-num[ind],num);

    return min(take,notTake);
}
int minimumElements(vector<int> &num,int target){
    int n=num.size();
    int ans=f(n-1,target,num);
    if(ans>=1e9) return -1;
    return ans;
}
int main() {
    vector<int> coins = {1, 2, 5}; // Example coins
    int target = 11; // Example target
    
    int result = minimumElements(coins, target);
    cout << "Minimum number of coins needed: " << result << endl;

    return 0;

}