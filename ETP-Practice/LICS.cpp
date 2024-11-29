#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> v){
    vector<int> T(v.size(),1);
    for(int j=1;j<v.size();j++){
        for(int i=0;i<j;i++){
            if(v[i]<v[j]){
                T[j]=max(T[j],T[i]+1);
            }
        }
    }
    int m=INT_MIN;
    for(int i=0;i<T.size();i++){
        if(T[i]>m){
            m=T[i];
        }
    }
    return m;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){

        cin>>v[i];
    }
    int a=LIS(v);
    cout<<a;
    return 0;
}