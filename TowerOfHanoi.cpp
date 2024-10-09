#include <iostream>
using namespace std;

void TOH(int n,char s,char a,char d){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    TOH(n-1,s,d,a);
    cout<<"Move disk "<<n<<" from "<<s<<" to "<<d<<endl;
    TOH(n-1,a,s,d);
}

int main() {
    int n;
    cin>>n;
    char A='1',B='2',C='3';
    TOH(n,A,B,C);
    return 0;
}