#include <iostream>
using namespace std;

int main() {
    int ratings[7]={1,2,3,4,5,2,1};
    int candy[7];
    for(int i=0;i<7;i++){
        candy[i]=1;
    }
    for(int i=1;i<7;i++){
        if(ratings[i]>ratings[i-1]){
            candy[i]=candy[i-1]+1;
        }
    }
    int count=candy[6];
    for(int i=5;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            candy[i]=max(candy[i],1+candy[i+1]);
        }
        count+=candy[i];
    }
    cout<<count;
    return 0;
}