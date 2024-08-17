#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        data=x;
        next=nullptr;
    }
};
void rPrint(Node* head){
    if(head==nullptr){
        return;
    }
    cout<<head->data<<" ";
    rPrint(head->next);
}
void Print(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    rPrint(head);
    cout<<endl;
    Print(head);
    return 0;
}