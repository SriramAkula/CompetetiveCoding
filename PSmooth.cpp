#include <iostream>
using namespace std;

int main() {
    int n;
    int p;
    cin>>n;
    cin>>p;
    if(p>=n){
        cout<<"P Smooth";
        return 0;
    }
    while(n%2==0){
        n=n/2;
    }
    int lpf=2;
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            n=n/i;
            lpf=i;
        }

    }
    if(n>1){
        lpf=n;
    }
    if(lpf<=p){
        cout<<"P Smooth";
    }else{
        cout<<"Not P Smooth";
    }
    return 0;
}