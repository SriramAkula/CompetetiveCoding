#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
};
    TreeNode* addNode(int x){
        TreeNode* newNode=new TreeNode();
        newNode->data=x;
        newNode->left=newNode->right=NULL;
        return newNode;
    }
    void inOrder(TreeNode* root){
        if(!root){
            return;
        }
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
        cout<<root->data<<" End ";
    }
    void iterativeInOrder(TreeNode* root){
        stack<TreeNode*> s;
        
        while(root!=NULL || !s.empty()){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            cout<<root->data<<" ";
            root=root->right;
        }
    }

int main() {
    TreeNode* root=addNode(1);
    root->left=addNode(2);
    root->left->left=addNode(4);
    root->right=addNode(3);
    root->left->right=addNode(5);
    root->left->right->left=addNode(9);
    root->right->right=addNode(7);
    inOrder(root);
    cout<<endl;
    iterativeInOrder(root);
    return 0;
}