/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//top-down method O(N^2)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        bool flag;
        flag = abs(maxDepth(root->left)-maxDepth(root->right))>1 ? false : true;
        return isBalanced(root->left) && isBalanced(root->right) && flag;
    }
    int maxDepth(TreeNode *root){
        if(root==nullptr)
            return 0;
        int leftDepth, rightDepth;
        leftDepth = maxDepth(root->left);
        rightDepth = maxDepth(root->right);
        return 1 + ((leftDepth>rightDepth) ? leftDepth : rightDepth);
    }
};

//down-top method O(N)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
    int dfsHeight(TreeNode *root){
        if(root==nullptr)
            return 0;
        int leftHeight = dfsHeight(root->left);
        if(leftHeight==-1) return -1;
        int rightHeight = dfsHeight(root->right);
        if(rightHeight==-1) return -1;
        if(abs(leftHeight-rightHeight)>1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};
