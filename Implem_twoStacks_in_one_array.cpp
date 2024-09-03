#include <iostream>
using namespace std;

    int arr[5];
    int top1,top2,n;

void push1(int k){
    if(top1==n/2){
        cout<<"Stack 1 Overflow"<<endl;
        return;
    }
    arr[top1]=k;
    cout<<"Pushed "<<k<<" in Stack 1"<<endl;
    top1++;
}
void push2(int k){
    if(top2==n){
        cout<<"Stack 2 Overflow"<<endl;
        return;
    }
    arr[top2]=k;
    cout<<"Pushed "<<k<<" in Stack 2"<<endl;
    top2++;
}
int pop1(){
    if(top1==0){
        return -1;
    }
    
    top1--;
    return arr[top1];
   
}
int pop2(){
    if(top2==n/2){
        return -1;
    }
    
    top2--;
    return arr[top2];
   
}


void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    n=5;
    top1=0;
    top2=n/2;
    push1(1);
    push1(2);
    push2(3);
    push2(4);
    push1(5);
    push2(6);
    push2(7);
    cout<<pop1()<<endl;
    cout<<pop1()<<endl;
    cout<<pop1()<<endl;
    cout<<pop2()<<endl;
    cout<<pop2()<<endl;
    cout<<pop2()<<endl;
    return 0;
}