#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* create(int x){
    Node* node=new Node();
    node->data=x;
    node->left=node->right=nullptr;
    return node;
}
Node* build(){
    int ele;
    cin>>ele;
    if(ele==-1) return nullptr;
    queue<Node* > q;
    Node* root=create(ele);
    q.push(root);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        if(l!=-1){
            node->left=create(l);
            q.push(node->left);
        }
        if(r!=-1){
            node->right=create(r);
            q.push(node->right);
        }
    }
    return root;
}
void postOrder(Node* root){
    if(!root){
        return;
    }
    stack<Node* > st1,st2;
    st1.push(root);
    while(!st1.empty()){
        Node* node=st1.top();
        st1.pop();
        st2.push(node);
        if(node->left){
            st1.push(node->left);
        }
        if(node->right){
            st1.push(node->right);
        }

    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}
int main() {
    Node* root=build();
    postOrder(root);
    return 0;
}