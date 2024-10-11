#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 0;
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* slow = temp;
        ListNode* fast = temp;
        
        // Move 'fast' pointer 'n+1' steps forward
        while (c <= n) {
            fast = fast->next;
            c++;
        }

        // Move both pointers until 'fast' reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node
        slow->next = slow->next->next;
        
        return temp->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array of values
ListNode* createList(std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5};  // Example list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createList(values);

    Solution sol;
    int n = 2;
    
    std::cout << "Original list: ";
    printList(head);

    head = sol.removeNthFromEnd(head, n);

    std::cout << "List after removing " << n << "-th node from end: ";
    printList(head);

    return 0;
}
