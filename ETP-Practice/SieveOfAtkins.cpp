#include <bits/stdc++.h>
using namespace std;

void SOA(int limit){
    vector<bool> sieve(limit+1,false);
    
    if(limit>2){
        sieve[2]=true;
    }
    if(limit>3){
        sieve[3]=true;
    }

    for(int x=1;x*x<limit;x++){
        for(int y=1;y*y<limit;y++){
            int n=(4*x*x)+(y*y);
            if(n<=limit && (n%12==1 || n%12==5)){
                sieve[n]=true;
            }
            n=(3*x*x)+(y*y);
            if(n<=limit && (n%12==7)){
                sieve[n]=true;
            }
            n=(3*x*x)-(y*y);
            if(x>y && n<=limit && (n%12==11)){
                sieve[n]=true;
            }
        }
    }
    for(int i=5;i*i<=limit;i++){
        if(sieve[i]){
            for(int r=i*i;r<=limit;r+=i*i){
                sieve[r]=false;
            }
        }
    }
    for (int a = 1; a <= limit; a++)
        if (sieve[a])
            cout << a << " ";
    cout << "\n";

}

int main() {
    SOA(30);
    return 0;
}