#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int primes[n];
    for(int i=2;i<=n;i++){
        primes[i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=i*i;j<=n;j+=i){
            primes[j]=0;
        }
    }
    for(int i=2;i<=n;i++){
        if(primes[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}