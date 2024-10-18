#include <iostream>
using namespace std;
#define MAX 100

int arr[MAX];  // Array to hold stack elements
int top = -1;  // Stack top initialized to -1

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = x;  // Increment top and then assign x to arr[top]
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return arr[top--];  // Return top element and decrement top
}

int peek() {
    if (!isEmpty()) {
        return arr[top];  // Return top element
    }
    cout << "Stack is empty" << endl;
    return -1;  // Return -1 if stack is empty
}

// Recursive function to insert an element in a sorted order
void insertSorted(int ele) {
    if (isEmpty() || peek() <= ele) {
        push(ele);
        return;
    }
    int temp = pop();  // Pop the top element
    insertSorted(ele);  // Recursively call to insert the element in the sorted part
    push(temp);  // Push the previously popped element back
}

// Recursive function to sort the stack
void sortStack() {
    if (isEmpty()) {
        return;
    }
    int temp = pop();  // Pop the top element
    sortStack();  // Recursively sort the rest of the stack
    insertSorted(temp);  // Insert the popped element in the sorted stack
}

// Function to print the stack
void print() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";  // Print elements from top to bottom
    }
    cout << endl;
}

int main() {
    // Push elements onto the stack
    push(45);
    push(90);
    push(12);
    push(6);
    push(9);
    push(14);

    // Print the original stack
    cout << "Original Stack: " << endl;
    print();

    // Sort the stack
    cout << "Sorted Stack: " << endl;
    sortStack();

    // Print the sorted stack
    print();

    return 0;
}
