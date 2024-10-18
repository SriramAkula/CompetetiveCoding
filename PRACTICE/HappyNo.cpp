#include <iostream>
using namespace std;

int sumOfSquares(int n){
    int sum=0;
    while(n>0){
        int temp=n%10;
        sum+=temp*temp;
        n=n/10;
    }
    return sum;
  
}

bool isHappy(int n){
    int first=n;
    int last=n;
    do{
        first=sumOfSquares(first);
        last=sumOfSquares(sumOfSquares(last));
    }while(first!=last);
    return first==1;
}
int nextHappy(int n){
    int num=n+1;
    while(!isHappy(num)){
        num++;
    }
    return num;
}

int main() {
    cout<<nextHappy(8);
    return 0;
}