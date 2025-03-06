#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* addNode(int x){
    TreeNode* newNode=new TreeNode();
    newNode->val=x;
    newNode->left=newNode->right=NULL;
    return newNode;
}
bool isSymmetric(TreeNode* root) {
    if(!root || (!root->left && !root->right)){
        return true;
    }
    if((!root->left && root->right) || (!root->right && root->left)){
        return false;
    }
    queue<TreeNode*> q;
    TreeNode* left=root->left;
    TreeNode* right=root->right;
    if(left->val!=right->val){
        return false;
    }
    q.push(left);
    q.push(right);
    while(!q.empty()){
        TreeNode* l=q.front();
        q.pop();
        TreeNode* r=q.front();
        q.pop();
        if(!l && !r){
            continue;
        }
        if((!l && r) || (!r && l)){
            return false;
        }
        if(l->val!=r->val){
            return false;
        }
        q.push(l->left);
        q.push(r->right);
        q.push(l->right);
        q.push(r->left);
    }
    return true;
    
}
int main() {
    TreeNode* root=addNode(1);
    root->left=addNode(2);
    root->left->left=addNode(3);
    root->left->right=addNode(4);
    root->right=addNode(2);
    root->right->right=addNode(3);
    root->right->left=addNode(4);
    bool res=isSymmetric(root);
    cout<<res<<endl;
    return 0;
}