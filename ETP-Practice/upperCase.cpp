#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s1;
    cin>>s1;

    char c='\0';

    for(char ch:s1){
        if(ch>='A'&&ch<='Z'){
            c=ch;
            break;
        }
    }
    int count=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]==c){
            count++;
        }
    }
    cout<<count;
}
