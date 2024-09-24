#include <bits/stdc++.h>
using namespace std;
stack<int> s1;
stack<int> s2;
int minE=INT_MAX;

void push(int k){
    if(k<minE){
        minE=k;
    }
    s1.push(k);
    cout<<"Pushed: "<<k<<endl;
    s2.push(minE);
    
    
}
void pop(){
    if(s1.empty()){
        cout<<"No Elements to Pop"<<endl;
    }
    cout<<"Popped: "<<s1.top()<<endl;
    s1.pop();
    s2.pop();
    

}

int findMin(){
    if(s2.empty()){
        return -1;
    }
    cout<<"Min: ";
    return s2.top();
}



int main() {
    push(10);
    push(7);
    push(12);
    push(5);
    push(6);
    push(2);
    cout<<findMin()<<endl;
    push(1);
    cout<<findMin()<<endl;
    pop();
    pop();
    cout<<findMin()<<endl;
    push(2);
    pop();
    pop();
    cout<<findMin()<<endl;

    return 0;
}