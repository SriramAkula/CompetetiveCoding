#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            // If temp1 reaches the end of list A, switch to headB
            temp1 = (temp1 == nullptr) ? headB : temp1->next;
            
            // If temp2 reaches the end of list B, switch to headA
            temp2 = (temp2 == nullptr) ? headA : temp2->next;
        }

        return temp1; // This will either be the intersection node or nullptr if no intersection exists.

    }
};

// Helper function to print the list from a given node
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Creating two intersecting linked lists
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // List A: 1 -> 2 -> 3 -> 8 -> 10
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    // List B: 4 -> 8 -> 10
    ListNode* headB = new ListNode(4);
    headB->next = common;

    Solution solution;
    ListNode* intersectionNode = solution.getIntersectionNode(headA, headB);

    // Printing the result
    if (intersectionNode) {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
