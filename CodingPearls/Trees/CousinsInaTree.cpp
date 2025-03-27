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
bool isCousins(TreeNode* root, int x, int y) {
    if(!root){
        return false;
    }
    queue<TreeNode*> q;
    q.push(root);
        bool x_found=false;
        bool y_found=false;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->val == x){
                x_found=true;
            }
            if(node->val == y){
                y_found=true;
            }
            if(node->left && node->right){
                if((node->left->val==x && node->right->val==y) || (node->left->val==y && node->right->val==x)){
                    return false;
                }
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
        if(x_found && y_found){
            return true;
        }else if((!x_found && y_found) || (x_found && !y_found) ){
            return false;
        }
    }
    return x_found==y_found;
}
int main() {
    TreeNode* root=addNode(2);
    root->left=addNode(4);
    root->right=addNode(6);
    root->left->left=addNode(7);
    root->left->right=addNode(8);
    root->right->left=addNode(9);
    root->right->right=addNode(10);
    root->left->right->left=addNode(12);
    root->right->left->right=addNode(14);
    bool res=isCousins(root,7,10);
    cout<<res;

    return 0;
}