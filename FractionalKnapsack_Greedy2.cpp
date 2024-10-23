#include <bits/stdc++.h>
using namespace std;

struct Knapsack{
    int weight;
    int value;
    double profit;
}Knapsack[3];

bool comp(Knapsack a,Knapsack b){
    a.profit=(double) a.value/a.wt;
    b.profit=(double) b.value/b.wt;
    return a.profit>b.profit;
}

int main() {
    int weights[3]={10,20,30};
    int values[3]={50,70,90};
    int W=50;
    for(int i=0;i<3;i++){
        Knapsack[i].weight=weights[i];
        Knapsack[i].value=values[i];
    }
    sort(Knapsack,Knapsack+3,comp);
    double profit;
    for(int i=0;i<3;i++){
        if(Knapsack[i].weight<=W){
            W-=Knapsack[i].weight;
            profit+=Knapsack[i].value;
        }else{
            profit+=W*Knapsack[i].profit;
            W=0;
        }
    }
    cout<<profit;

    return 0;
}