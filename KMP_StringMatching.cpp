#include <iostream>
using namespace std;
int kmp(string s1,string s){
    if(s.length()==1){
        return 0;
    }
    int lps[s.length()];
    lps[0]=0;
    int j=0;
    int i=1;
    while(i<s.length()){
        if(s[j]==s[i]){
            j++;
            lps[i]=j;
            i++;
        }else if(j>0){
            j=lps[j-1];
        }else{
            lps[i]=0;
            i++;
        }
    }
    i=0;
    j=0;
    while(s1.length()>i){
        if(s[j]==s1[i]){
            i++;
            j++;
            if (j == s.length()) {
                return i - j; 
            }
        } else if (j > 0) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    return -1;
}
int main() {
    // int r=lps("aaabcdaa");
    // int r=lps("bcbc");
    // int r=lps("aaaaabcdaaaazzzz");
    // int r=lps("bbaddaccad");
    // cout<<r;
    int r=kmp("aaaaaabcdaaazzzz","aaabcdaa");
    cout<<r;
    return 0;
}