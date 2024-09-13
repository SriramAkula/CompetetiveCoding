#include <iostream>
using namespace std;
int gcd(int a,int b){
    // if(b==0){
    //     return a;
    // }
    // return gcd(b,a%b);

    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
int lcm(int a,int b){
    return (a/gcd(a,b)*b);
}
int main() {
    cout<<gcd(11,12)<<endl;
    cout<<lcm(5,20);
    return 0;
}