#include <bits/stdc++.h>
using namespace std;

int main() {
    int m=4;
    int n=4;
    int arr[m][n]={{1,2,1,1},{2,4,1,1},{5,1,2,1},{6,2,1,1}};
    unordered_map<int,int> mp;
    for(int k=0;k<n;k++){
        mp[arr[0][k]]++;
    }
    for(int i=1;i<m;i++){
        unordered_map<int,int> mp1;
        for(int j=0;j<n;j++){
            mp1[arr[i][j]]++;

        }
        for(auto &it:mp){
            if(mp1.find(it.first)!=mp1.end()){
                it.second=min(it.second,mp1[it.first]);
            }
        }
    }
    for(auto &it:mp){
        for(int i=0;i<it.second;i++){
            cout<<it.first<<endl;
        }
    }
    return 0;
}