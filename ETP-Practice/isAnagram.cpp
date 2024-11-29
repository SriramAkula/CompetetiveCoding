#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    int arr[26]={};
    for(int i=0;i<s1.length();i++){
        s1[i]=tolower(s1[i]);
        s2[i]=tolower(s2[i]);
        arr[s1[i]-'a']++;
        arr[s2[i]-'a']--;
    }
    for(int i:arr){
        if(i!=0){
            return false;
        }
    }
    return true;
}

int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    bool f=isAnagram(s1,s2);
    cout<<f;
    return 0;
}