#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* check = nullptr;
Node* head = nullptr;

Node* push(int x) {
    Node* temp = new Node(x);
    if (x == 4) {
        check = temp; // Store the node with value 4
    }
    if (x == 6) {
        temp->next = check; // Create a cycle by pointing to the node with value 4
    }
    if (head == nullptr) {
        head = temp; // Initialize the head of the list
        return head;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = temp; // Add the new node to the end of the list
    return head;
}

Node* detectCycle() {
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* fast=head;
    Node* slow=head;

    while(fast!=nullptr && fast->next!=nullptr){
        
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            Node* entry=head;
            while(slow!=entry){
                entry=entry->next;
                slow=slow->next;
            }
            return slow;
        }
        

        
    }
    return nullptr;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4); // This node will be the start of the cycle
    push(5);
    push(6); // This creates a cycle, node 6 points to node 4

    Node* cyHead = detectCycle();
    if (cyHead != nullptr) {
        cout << "Cycle detected at node with data: " << cyHead->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    return 0;
}
