#include <iostream>
using namespace std;

int size=0;
int arr[10];
int cap=10;

void push(int x){
    if(size==cap){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    arr[size]=x;
    size++;
    cout<<"Pushed "<<x<<endl;
}
void pop(){
    if(size==0){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    cout<<"Popped "<<arr[size-1]<<endl;
    size--;
}
bool isEmpty(){
    if(size==0){
        return true;
    }
    return false;
}
int top(){
    if(!isEmpty()){
        return arr[size-1];
    }else{
        cout<<"Stack underflow"<<endl;
    }
}
int main() {
    push(1);
    push(2);
    push(3);
    pop();
    push(4);
    pop();
    cout<<top()<<endl;
    return 0;
}