#include <iostream>
using namespace std;

class MyStack{
    struct Node{
    int data;
    Node* next;

    Node(int x){
        data=x;
        next=nullptr;
    }
};
    Node* head=nullptr;

    void push(int x){
        Node* temp=new Node(x);
        temp->next=head;
        head=temp;
    }
    void pop(){
    if(head==nullptr){
        return;
    }
    else{
        head=head->next;
    }
}
};


int main() {
    
    return 0;
}