#include <iostream>
using namespace std;

class LinkedList {
    private:
    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

    Node* head;

    public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int x) {
        Node* temp = new Node(x);
        if (head == nullptr) {
            head = temp;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }

    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    Node* reverseRec(Node* curr){
        if(curr==nullptr || curr->next==nullptr){
            return curr;
        }
        Node* newHead=reverseRec(curr->next);
        Node* front=curr->next;
        front->next=curr;
        curr->next=nullptr;
        return newHead;
    }

    void reverse(){
        head=reverseRec(head);
    }
};

int main() {
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);

    ll.print();
    ll.reverse();
    ll.print();

    return 0;
}
