#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void SumPrime(int n){
    vector<int> v(n+1,1);
    for(int i=2;i*i<=n;i++){
        if(v[i]==1){
            for(int j=i*i;j<=n;j+=i){
                if(v[j]==1){
                    v[j]=0;
                }
            }
        }
    }
    int sum=0;
    for(int i=2;i<=n;i++){
        if(v[i]==1){
            sum+=i;
            cout<<i<<" ";
        }
    }
        cout<<endl;
        cout<<sum;
}

int main() {
    SumPrime(30);
    return 0;
}