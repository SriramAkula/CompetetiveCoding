#include <iostream>
using namespace std;

bool isAnagram(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    
    for(int i=0;i<s1.length();i++){
        int idx1=s1[i]-'a';
        arr[idx1]++;
        int idx2=s2[i]-'a';
        arr[idx2]--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
            return false;
            break;
        }
    }
    return true;
    cout<<endl;

}
int StepsAnagram(string s1,string s2){
    
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    for(int i=0;i<s1.length();i++){
        int idx1=s1[i]-'a';
        arr[idx1]++;
    }
    for(int i=0;i<s2.length();i++){
        int idx2=s2[i]-'a';
        arr[idx2]--;
    }
    int steps=0;
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
            steps+=abs(arr[i]);
            
        }
    }
    return steps;

}



int main() {
    bool res=isAnagram("abc","bac");
    cout<<res<<endl;
    cout<<StepsAnagram("aabc","aa");
    return 0;
}