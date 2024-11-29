#include <iostream>
#include<vector>
using namespace std;

void SOE(int n){
    vector<bool> sieve(n+1,true);
    for(int p=2;p*p<=n;p++){
        if(sieve[p]==true){
            for(int i=p*p;i<=n;i+=p){
                sieve[i]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(sieve[i]==1)
            cout<<i<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    SOE(n);
    return 0;
}