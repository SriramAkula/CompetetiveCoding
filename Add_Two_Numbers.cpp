/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* revList(ListNode* head){
        ListNode* curr=head;
        ListNode* next=nullptr;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    long long ToDigit(ListNode* head){
        long long dig=0;
        ListNode* curr=head;
        while(curr!=nullptr){
            long long n=curr->val;
            dig=dig*10+n;
            curr=curr->next;
        }
        return dig;
    }
    void insertAtEnd(ListNode*& head,int x){
    ListNode* temp=new ListNode(x);
    if(head==nullptr){
        head = temp;
        return;
    }
    ListNode* curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=temp;

}
    ListNode* ToList(int n){
        if (n == 0) { 
            return new ListNode(0);
        }
        ListNode* temp=nullptr;
        while(n>0){
            int k=n%10;
            insertAtEnd(temp,k);
            n=n/10;
        }
        return temp;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ll1=revList(l1);
        ListNode* ll2=revList(l2);
        long long num1=ToDigit(ll1);
        long long num2=ToDigit(ll2);
        long long res=num1+num2;
        ListNode* resList=ToList(res);
        return resList;
    }
};