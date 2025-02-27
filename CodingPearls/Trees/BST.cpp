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
    // bool checkBST(TreeNode* root){
    //     if(!root){
    //         return true;
    //     }
    //     stack<TreeNode*> s;
    //     while(root!=NULL || !s.empty()){
    //         while(root!=NULL){
    //             s.push(root);
    //             root=root->left;
    //         }
    //         root=s.top();
    //         s.pop();
    //         if(prev!=nullptr && prev->data>=root->data){
    //             return false;
    //         }
    //         prev=root;
    //         root=root->right;
    //     }
    // }
    bool checkBSTPre(TreeNode* root,int minVal,int maxVal){
        if(!root){
            return true;
        }
        if(minVal>root->data || maxVal<root->data) return false;
        return checkBSTPre(root->left,minVal,root->data) && checkBSTPre(root->right,root->data,maxVal);

    }
    
    TreeNode* prev=nullptr;
int main() {
    TreeNode* root=addNode(50);
    root->left=addNode(40);
    root->left->left=addNode(30);
    root->right=addNode(60);
    root->left->right=addNode(45);
    root->right->left=addNode(55);
    root->right->right=addNode(65);
    // inOrder(root);
    // cout<<endl;
    // bool flag=checkBST(root);
    // cout<<flag<<endl;
    int a=INT_MIN;
    int b=INT_MAX;
    bool flag=checkBSTPre(root,a,b);
    cout<<flag<<endl;

    return 0;
}