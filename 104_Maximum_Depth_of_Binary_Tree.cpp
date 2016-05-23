/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int leftDepth, rightDepth;
        leftDepth = maxDepth(root->left);
        rightDepth = maxDepth(root->right);
        return 1 + ((leftDepth>rightDepth) ? leftDepth : rightDepth);
    }
};
