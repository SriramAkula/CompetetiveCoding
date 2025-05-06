#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next; 

    Node(int val) {
        data = val;
        left = right = next = nullptr;
    }
};

void populateNext(Node* root, Node*& next) {
    if (!root) return;

    populateNext(root->right, next);

    root->next = next;

    next = root;

    populateNext(root->left, next);
}

void populateInorderSuccessor(Node* root) {
    Node* next = nullptr;
    populateNext(root, next);
}

void printInorderSuccessors(Node* root) {
    if (!root) return;
    printInorderSuccessors(root->left);
    cout << "Node " << root->data << " -> Successor ";
    if (root->next)
        cout << root->next->data << endl;
    else
        cout << "NULL" << endl;
    printInorderSuccessors(root->right);
}

// Sample usage
int main() {

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    populateInorderSuccessor(root);
    printInorderSuccessors(root);

    return 0;
}
