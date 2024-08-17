#include <iostream>
#include <stack>
using namespace std;
class MyQueue{
public:
    stack<int> s1;
    stack<int> s2;


void enque(int k){
    s1.push(k);
}
void deque(){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
     if (!s2.empty()) {
            cout << s2.top() << " ";
            s2.pop();
        } else {
            cout << "Queue is empty!" << endl;
        }
    
}
};

int main() {

    MyQueue q1;
    q1.enque(4);
    q1.enque(5);
    q1.enque(6);
    q1.deque();
    q1.enque(7);
    q1.deque();


    
    return 0;
}