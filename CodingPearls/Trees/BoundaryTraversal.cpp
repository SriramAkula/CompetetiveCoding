#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void leftTraversal(Node* node, vector<int>& result) {
        if (!node || (!node->left && !node->right)) return;

        result.push_back(node->data);
        if (node->left) {
            leftTraversal(node->left, result);
        } else {
            leftTraversal(node->right, result);
        }
    }

    void leafTraversal(Node* node, vector<int>& result) {
        if (!node) return;
        if (!node->left && !node->right) {
            result.push_back(node->data);
            return;
        }
        leafTraversal(node->left, result);
        leafTraversal(node->right, result);
    }

    void rightTraversal(Node* node, vector<int>& v) {
        if (!node || (!node->left && !node->right)) return;

        if (node->right) {
            rightTraversal(node->right, v);
        } else {
            rightTraversal(node->left, v);
        }
        v.push_back(node->data); // Push after recursion to reverse order
    }

    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};

        vector<int> result, rightBoundary;
        result.push_back(root->data);

        if (!root->left && !root->right) return result; // Single node case

        leftTraversal(root->left, result);
        leafTraversal(root->left, result);
        leafTraversal(root->right, result);
        rightTraversal(root->right, rightBoundary);

        result.insert(result.end(), rightBoundary.begin(), rightBoundary.end());
        return result;
    }
};

// **Main Function to Test**
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);

    Solution sol;
    vector<int> boundary = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int num : boundary) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
