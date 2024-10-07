#include <iostream>
using namespace std;

class MyStack {
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int x) {
            data = x;
            next = nullptr;
            prev= nullptr;
        }
    };
    int size=0;
    Node* head = nullptr;
    Node* mid=nullptr;

public:
    void push(int x) {
        size++;
        // cout<<size<<endl;
        Node* temp = new Node(x);
        if(head==nullptr){
            head=temp;
            mid=temp;
            return;
        }
        temp->next = head;
        head = temp;
        head->next->prev=temp;
        if(size%2==1){
            mid=mid->prev;
        }
    }

    int pop() {
        if (head == nullptr) {
            // cout << "Stack underflow" << endl;
           return -1;
        }
        size--;
        Node* temp = head;
        int val=temp->data;
        head = head->next;
        if(head!=nullptr){
            head->prev=nullptr;
        }
        delete temp; 
        if(size%2==0){
            mid=mid->next;
        }
        return val;
    }

    int top() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return head->data;
    }

   
    bool isEmpty() {
        return head == nullptr;
    }

    int midddle(){
        if(mid==nullptr){
            return -1;
        }
        return mid->data;
    }
    

};

int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    // cout << "Top element: " << stack.top() << endl; 
    cout<<"Middle element: "<<stack.midddle()<<endl;
    stack.pop();
    cout<<"Middle element: "<<stack.midddle()<<endl;
    stack.pop();
    cout<<"Middle element: "<<stack.midddle()<<endl;
    stack.pop();
    cout<<"Middle element: "<<stack.midddle()<<endl;
    stack.pop();
    cout<<"Middle element: "<<stack.midddle()<<endl;
    
    // cout << "Top element: " << stack.top() << endl; 

     

    

    return 0;
}
