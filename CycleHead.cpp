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
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // No cycle if the list is empty or has only one node
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) { // Proper condition to avoid nullptr access
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // Cycle detected
            Node* entry = head;
            while (entry != slow) { // Find the entry point of the cycle
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // Return the node where the cycle begins
        }
    }
    return nullptr; // No cycle found
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
