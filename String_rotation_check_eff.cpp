#include <bits/stdc++.h>
using namespace std;

isRotated(string s1,string s2){
    if(s1.length()!=s2.length()) return false;
    s1=s1+s2;
    return (s1.find(s2)!=string::npos);
}

int main() {
    string s1="abcd";
    string s2="dabc";
    cout<<isRotated(s1,s2);
    return 0;
}