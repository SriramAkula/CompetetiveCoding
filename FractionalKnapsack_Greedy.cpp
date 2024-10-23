

#include <iostream>
using namespace std;

int main() {
    int weights[3]={10,20,30};
    int values[3]={50,70,90};
    int W=50;
    double WPV[3]={5,3.5,3};
    int profit=0;
    for(int i=0;i<3;i++){
        if(weights[i]<=W){
            W-=weights[i];
            profit+=values[i];
        }else{
            profit+=W*WPV[i];
        }
    }
    cout<<profit;
    return 0;
}