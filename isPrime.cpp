// CSE-330 
// Twisting Prime No
// Roll No - 05

#include <iostream>
using namespace std;

int reverse(int n){
    int res=0;
    while(n>0){
        int temp=n%10;
        res=res*10+temp;
        n=n/10;
    }
    return res;
}

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}



int main() {
    // cout<<isPrime(3)<<endl;
    // cout<<isPrime(32);
    // cout<<reverse(32);

    int n;
    cin>>n;

    cout<<isPrime(n)<<endl;
    cout<<isPrime(reverse(n));
    
    return 0;
}