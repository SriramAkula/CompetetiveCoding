#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "1,2,3,40,50";
    vector<int> vec;
    string s1="";
    for(int i=0;i<s.length();i++){
        if(s[i]==','){
            vec.push_back(stoi(s1));
            s1="";

        }else{
            s1+=s[i];
        }
    }
    vec.push_back(stoi(s1));
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}
