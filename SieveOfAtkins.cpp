#include <iostream>
using namespace std;

int main() {
    int n1;
    cin>>n1;
    bool sieve[n1];
    for(int i=0;i<=n1;i++){
        sieve[i]=false;
    }
    if (n1 > 2)
        sieve[2] = true;
    if (n1 > 3)
        sieve[3] = true;
    
    for(int x=1;x*x<=n1;x++){
        for(int y=1;y*y<=n1;y++){

            int n=(4*x*x)+(y*y);
            if(n<=n1 && (n%12==1 || n%12==5)){
                sieve[n]=true;
            }
            n=(3*x*x)+(y*y);
            if(n<=n1 && (n%12==7)){
                sieve[n]=true;
            }
            n=(3*x*x)-(y*y);
            if(n<=n1 && (n%12==11)){
                sieve[n]=true;
            }

        }
    }
    for(int i=5;i*i<=n1;i++){
        if(sieve[i]){
            for(int r=i*i;r<=n1;r+=i*i){
                sieve[r]=false;
            }
        }
    }
    for (int a = 1; a <= n1; a++)
        if (sieve[a])
            cout << a << " ";
    cout << "\n";
    return 0;
}