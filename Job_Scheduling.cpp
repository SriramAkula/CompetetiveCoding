#include <bits/stdc++.h>
using namespace std;

struct task{
    char id;
    int deadline;
    int profit;
}tasks[5]={{'a',3,20},{'b',2,27},{'c',1,40},{'d',1,35},{'e',2,50}};

bool comp(task a,task b){
    return a.profit>b.profit;
}
int main() {
    int n=5;
    sort(tasks,tasks+n,comp);
    int res[n];
    bool slots[n]={};
    for(int i=0;i<n;i++){
        for(int j=min(n,tasks[i].deadline)-1;j>=0;j--){
            if(slots[j]==false){
                slots[j]=true;
                res[j]=i;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(slots[i]==true){
            cout<<tasks[i].id;
        }
    }
    return 0;
}