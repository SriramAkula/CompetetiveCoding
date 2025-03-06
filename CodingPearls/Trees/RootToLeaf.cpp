#include <bits/stdc++.h>
using namespace std;

int sum=0;
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
void dfs(TreeNode* root,int currSum){
    if(root==NULL){
        return;
    }
    currSum=currSum*10+root->data;
    if(root->left==NULL && root->right==NULL){
        sum+=currSum;
        return;
    }
    dfs(root->left,currSum);
    dfs(root->right,currSum);
}
void bfs(TreeNode* root){
    queue<TreeNode*> q1;
    queue<int> q2;
    if(root==NULL){
        cout<<0;
        return;
    }
    q1.push(root);
    q2.push(0);
    while(!q1.empty()){
        TreeNode* node=q1.front();
        q1.pop();
        int curr=q2.front();
        q2.pop();
        curr=curr*10+node->data;
        if(node->left==NULL && node->right==NULL){
            sum+=curr;
        }else{
            if(node->left){
                q1.push(node->left);
                q2.push(curr);
            }
            if(node->right){
                q1.push(node->right);
                q2.push(curr);
            }
        }
    }
}
int main() {
    TreeNode* root=addNode(4);
    root->left=addNode(9);
    root->left->left=addNode(2);
    root->left->right=addNode(1);
    root->right=addNode(5);
    // dfs(root,0);
    bfs(root);
    
    cout<<sum;
    return 0;
}