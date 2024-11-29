#include <bits/stdc++.h>
using namespace std;

void isPangram(string s){
    int arr[26]={};
    for(int i=0;i<26;i++){
        arr[s[i]-'a']=1;
    }
    for(int i=0;i<26;i++){
        if(arr[i]==0){
            cout<<char(i+'a');
        }
    }
}

int main() {
    string s;
    getline(cin,s);
    isPangram(s);
    return 0;
}