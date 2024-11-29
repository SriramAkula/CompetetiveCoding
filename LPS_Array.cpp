#include <iostream>
using namespace std;

int lps(string s){
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
    int max=0;
    for(int i=1;i<s.length();i++){
        if(lps[i]>max){
            max=lps[i];
        }
    }
    return max;
}
int main() {
    // int r=lps("aaabcdaa");
    // int r=lps("bcbc");
    // int r=lps("aaaaabcdaaaazzzz");
    int r=lps("bbaddaccad");
    cout<<r;
    return 0;
}