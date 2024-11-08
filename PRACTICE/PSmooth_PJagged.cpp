#include <iostream>
using namespace std;

int find_lpf(int n){
    while(n%2==0){
        n/=2;
    }
    int lpf=2;
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            n/=i;
            lpf=i;
        }
    }
    if(n>1){
        lpf=n;
    }
    return lpf;
}
int find_spf(int n){
    int spf=2;
    if(n%2==0){
        spf=2;
    }
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return i;
        }
    }
    return spf;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int c=0;
        int st,end,p;
        cin>>st>>end>>p;
        for(int i=st;i<=end;i++){
            int lpf=find_lpf(i);
            int spf=find_spf(i);
            if(lpf<=p && spf<=p){
                c++;
            }
        }
        cout<<c; 

    }
    return 0;
}