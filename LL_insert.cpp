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

void insertAtBegining(Node*& head,int x){
    Node* temp=new Node(x);
    temp->next=head;
    head=temp;
}
void insertAtEnd(Node*& head,int x){
    Node* temp=new Node(x);
    if(head==nullptr){
        head = temp;
        return;
    }
    Node* curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=temp;

}
void insertAtPos(Node*& head,int x,int pos){
    Node* temp=new Node(x);
    if(pos==1){
        temp->next=head;
        head=temp;
        return;
    }
    Node* curr=head;
    for(int i=1;i<=pos-2 && curr!=nullptr;i++){
        curr=curr->next;
    }
    if (curr == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    temp->next=curr->next;
    curr->next=temp;
    cout<<"Element Inserted at POS"<<endl;


}
void rPrint(Node* head){
    if(head==nullptr){
        return;
    }
    cout<<head->data<<" ";
    rPrint(head->next);
}

int main() {
    Node* head=nullptr;
    int n;
    cout << "Enter number of elements: ";
    cin>>n;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        insertAtEnd(head,k);
    }
    insertAtPos(head,100,2);
    insertAtPos(head,200,4);
    insertAtPos(head,200,10);
    cout << "The LinkedList: ";
    rPrint(head);

    return 0;
}