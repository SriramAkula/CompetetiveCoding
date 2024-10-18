#include <iostream>
using namespace std;

bool isSumStringUtil(string S,int beg,int len1,int len2){
    string s1=S.substr(beg,len1);
    string s2=S.substr(beg+len1,len2);
    long long num1=stoll(s1);
    long long num2=stoll(s2);
    string sum=to_string(num1+num2);
    int sumIndex=beg+len1+len2;
    if(S.substr(sumIndex,sum.length())!=sum){
        return false;
    }
    if(sumIndex + sum.length()==S.length()){
        return true;
    }
    return isSumStringUtil(S,beg+len1,len2,sum.length());
}

bool isSumString(string S){
    int n=S.length();
    for(int len1=1;len1<n;len1++){
        for(int len2=1;len1+len2<n;len2++){
            if(isSumStringUtil(S,0,len1,len2)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    string S;
    cout << "Enter the string: ";
    cin >> S;
    
    if (isSumString(S))
        cout << "1" << endl; // It's a sum-string
    else
        cout << "0" << endl; // It's not a sum-string
    return 0;
}