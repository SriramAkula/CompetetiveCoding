#include <bits/stdc++.h>
using namespace std;

bool isRotated(string s1,string s2){
    if(s1.length()!=s2.length()) return false;
    int n=s1.length();
    string s3="";
    for(int j=1;j<=n;j++){
        int k=j;
        for(int i=n-1;i>=n-k;i--){
            s3+=s1[i];
        }
        for(int i=0;i<n-k;i++){
            s3=s3+s1[i];
        }
        if(s3==s1){
            return true;
        }
    }
    return false;
} 
int main() {
    string s1="abcd";
    string s2="dabc";
    cout<<isRotated(s1,s2);
    return 0;
}