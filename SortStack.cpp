#include <iostream>
using namespace std;

int size = 0;
int arr[100];
int cap = 100;

void push(int x) {
    if (size == cap) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[size] = x;
    size++;
}

int pop() {
    if (size == 0) {
        cout << "Stack Underflow" << endl;
        return -1; 
    }
    size--;
    return arr[size]; 
}

bool isEmpty() {
    return size == 0;
}

int top() {
    if (!isEmpty()) {
        return arr[size - 1];
    } else {
        cout << "Stack underflow" << endl;
        return -1; 
    }
}

int peek() {
    if (isEmpty()) {
        return -1;
    }
    return arr[size - 1];
}

void insertSorted(int ele) {
    if (isEmpty() || peek() <= ele) {
        push(ele);
        return;
    }
    int temp = pop();
    insertSorted(ele);
    push(temp);
}

void sortStack() {
    if (isEmpty()) {
        return;
    }
    int temp = pop();
    sortStack();
    insertSorted(temp);
}

void print() {
    while (!isEmpty()) {
        cout << top() << " ";
        pop();
    }
    cout << endl;
}

int main() {
    push(3);
    push(2);
    push(1);
    sortStack();
    print(); 
    return 0;
}
