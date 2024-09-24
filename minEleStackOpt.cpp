#include <bits/stdc++.h>
using namespace std;
stack<int> s1;
int minE=INT_MAX;

void push(int k){
    if(k<=minE){
        s1.push(minE);
        minE=k;
    }
    s1.push(k);
    
    
}
void pop(){
    if(s1.empty()){
        cout<<"No Elements to Pop"<<endl;
    }
    if(minE==s1.top()){
        s1.pop();
        minE=s1.top();
        s1.pop();
    }else{
        s1.pop();
    }
    

}

int findMin(){
    if(s1.empty()){
        return -1;
    }
    cout<<"Min: ";
    return minE;
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