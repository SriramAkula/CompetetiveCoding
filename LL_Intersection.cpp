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
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        int cA = 0, cB = 0;
        
        // Get the length of list A
        while (curr1 != nullptr) {
            cA++;
            curr1 = curr1->next;
        }

        // Get the length of list B
        while (curr2 != nullptr) {
            cB++;
            curr2 = curr2->next;
        }

        // Reset pointers to head
        curr1 = headA;
        curr2 = headB;

        // Align both pointers at the same distance from the intersection
        while (cA != cB) {
            if (cA > cB) {
                curr1 = curr1->next;
                cA--;
            } else {
                curr2 = curr2->next;
                cB--;
            }
        }

        // Find the intersection point
        while (curr1 != curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr1;
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
