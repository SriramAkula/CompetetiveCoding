#include <iostream>
using namespace std;

void isPangram(string str){
    int arr[26];
    for(int i=0;i<str.length();i++){
        int idx=str[i]-'a';
        if(idx>=0 && idx<26){

            arr[idx]=1;
        }
    }
    for(int i=0;i<26;i++){
        if(arr[i]!=1){
            char c='a'+i;
            cout<<c;
        }
    }
    cout<<endl;
}

int main() {
    string str="aubvrtilo";
    string str1="a^&erbbAABC";
    
    isPangram(str);
    isPangram(str1);
    return 0;
}