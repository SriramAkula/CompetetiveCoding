#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n<2){
        cout<<0;
        return 0;
    }
    // if(n%2==0){
    //     cout<<2<<" ";
    // }
    while(n%2==0){
        cout<<2<<" ";
        n=n/2;
    }
    for(int i=3;i*i<=n;i+=2){
        // if(n%i==0){
        //     cout<<i<<" ";
        // }
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n!=1){
        cout<<n;
    }

    return 0;
}