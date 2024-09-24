#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end of the linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Recursive function to reverse the linked list
    Node* reverseRecursively(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        Node* rest = reverseRecursively(node->next);
        node->next->next = node;
        node->next = nullptr;
        return rest;
    }

    // Wrapper function to call the recursive reverse function
    void reverse() {
        head = reverseRecursively(head);
    }

    // Function to display the elements of the linked list
    void display() const {
        if (head == nullptr) {
            cout << "Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original Linked List: ";
    list.display();

    list.reverse();

    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}
