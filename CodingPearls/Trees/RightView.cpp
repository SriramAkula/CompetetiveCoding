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
vector<int> rightView(TreeNode* root){
    if(!root){
        return {};
    }
    queue<TreeNode* > q;
    q.push(root);
    vector<int> res;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(i==size-1){
                res.push_back(node->val);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return res;
}
void dfs(TreeNode* root,int level,vector<int> &ds){
    if(!root){
        return;
    }
    if(level==ds.size()){
        ds.push_back(root->val);
    }
    dfs(root->right,level+1,ds);
    dfs(root->left,level+1,ds);
}
void dfs1(TreeNode* root,int level,vector<int> &ds){
    if(!root){
        return;
    }
    if(level==ds.size()){
        ds.push_back(root->val);
    }else{
        ds[level]=root->val;
    }

    
    dfs1(root->left,level+1,ds);
    dfs1(root->right,level+1,ds);
}
int main() {
    TreeNode* root=addNode(10);
    root->left=addNode(20);
    root->left->right=addNode(40);
    root->left->right->left=addNode(7);
    root->left->right->left->right=addNode(8);
    root->right=addNode(2);
    root->right->right=addNode(4);
    root->right->right->left=addNode(5);
    root->right->right->right=addNode(6);
    // vector<int> res=rightView(root);
    // for(int i: res){
    //     cout<<i<<" ";
    // }
    vector<int> ds;
    dfs1(root,0,ds);
    for(int i: ds){
        cout<<i<<" ";
    }

    return 0;
}