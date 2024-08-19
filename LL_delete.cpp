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
Node* delHead(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    else{
        Node* temp=head->next;
        delete head;
        return temp;
    }
}
Node* delTail(Node* head){
    
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Node* curr=head;
    while(curr->next->next!=nullptr){
        curr=curr->next;
    }
    delete(curr->next);
    curr->next=nullptr;
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    head = delHead(head);  // Deleting the head node
    head = delTail(head);  // Deleting the tail node
    
    // Print the remaining list
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}