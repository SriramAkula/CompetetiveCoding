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

void sum_prime(int n){
    for(int i=2;i<=n/2;i++){
        bool a=isPrime(i);
        bool b=isPrime(n-i);
        if(a && b){
            cout<<i<<" "<<n-i<<endl;
            return;
        }
    }
    cout<<"No pairs found";
}

int main() {
    int n;
    cin>>n;

    sum_prime(n);
    return 0;
}