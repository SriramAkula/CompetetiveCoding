#include <bits/stdc++.h>
using namespace std;
int gfd(int num){
    while(num>=10){
        num/=10;
    }
    return num;
}
int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back(gfd(t));
    }
    sort(v.begin(),v.end(),greater<int>());
    if(n==1||v[0]==v[n-1]){
        cout<<v[0];
        return 0;
    }
    string largest="";
    string secLargest="";
    for(int i:v){
        largest+=to_string(i);
    }
    
    secLargest=largest;
    for(int i=v.size()-2;i>=0;--i){
        if(v[i]!=v[i+1]){
            swap(secLargest[i],secLargest[i+1]);
            break;
        }
    }
    cout<<secLargest;
    return 0;
}