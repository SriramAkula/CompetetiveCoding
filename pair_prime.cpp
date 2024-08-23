#include <iostream>
using namespace std;

bool isPrime(int n){
    bool flag=true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void pair_prime(int n){
    int a=0;
    int b=0;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            bool a=isPrime(i);
            bool b=isPrime(n/i);
            if(a && b){
                cout<<i<<" "<<n/i;
                return;
            }
        }
    }
    
}

int main() {
    int n;
    cin>>n;

    pair_prime(n);
    return 0;
}