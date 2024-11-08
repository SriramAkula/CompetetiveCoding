#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next = nullptr;
    }
}*head=nullptr;

void push(int x){
    Node* newNode=new Node(x);
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=newNode;
}
void display(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

Node* rem(Node* head,int n){
    Node* dummy=new Node(-1);
    dummy->next=head;
    Node* fast=dummy;
    Node* slow=dummy;
    int c=0;
    while(c<=n){
        fast=fast->next;
        c++;
    }
    while(fast!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return dummy->next;
}
int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    display(head);
    Node* newh=rem(head,5);
    display(newh);
    return 0;
}