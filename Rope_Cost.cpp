#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int rope[5]={4,3,2,7,9};
    int n=5;
    int sum=0;
    while(n>1){
        sort(rope,rope+n);
        int s=rope[0]+rope[1];
        for (int i=2;i<n;i++) {
            rope[i-2]=rope[i];
        }
        rope[n-2]=s;
        sum+=s;
        n--;

    }
    cout<<sum<<endl;
    
    return 0;
}