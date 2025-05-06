#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* create(int x){
    TreeNode* newNode=new TreeNode();
    newNode->data=x;
    newNode->left=newNode->right=nullptr;
    return newNode;
}
TreeNode* build(){
    int ele;
    cin>>ele;
    if(ele==-1) return nullptr;
    TreeNode* root=create(ele);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        TreeNode* node=q.front();
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

int main() {
    TreeNode* root=build();

    return 0;
}