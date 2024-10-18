#include <iostream>
using namespace std;
bool LuckyH(int n,int i=2){
    if(i>n){
        return true;
    }
    if(n%i==0){
        return false;
    }
    n=n-(n/i);
    return LuckyH(n,i+1);
}
bool isLucky(int n){
    return LuckyH(n);
}

int main() {
    cout<<isLucky(19);
    cout<<isLucky(5);
    return 0;
}