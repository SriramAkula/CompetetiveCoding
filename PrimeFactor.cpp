#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int flag=0;
    while(n%2==0){
        if(flag==0){
            flag=1;
            cout<<2<<" ";
        }
        n=n/2;
    }
    for(int i=3;i*i<=n;i+=2){
        flag=0;
        while(n%i==0){
            if(flag==0){
                flag=1;
                cout<<i<<" ";
            }
            n=n/i;
        }

    }
    if(n>1){
        cout<<n;
    }
    return 0;
}