#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int item) {
    if (st.empty()) {
        st.push(item);
        return;
    }
    
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, item);
    
    st.push(topElement);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }
    
    int topElement = st.top();
    st.pop();
    
    // Reverse the remaining stack
    reverseStack(st);
    
    // Insert the removed element at the bottom
    insertAtBottom(st, topElement);
}

// Utility function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    
    // Sample stack elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    cout << "Original Stack: ";
    printStack(st);
    
    reverseStack(st);
    
    cout << "Reversed Stack: ";
    printStack(st);
    
    return 0;
}