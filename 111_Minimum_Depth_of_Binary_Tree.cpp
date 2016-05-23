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
    int min = INT_MAX;
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        minDepthHelper(root, 1);
        return min;
    }
    void minDepthHelper(TreeNode *root, int depth){
        if(root->left==nullptr&&root->right==nullptr){
            if(depth<min) min = depth;
        }
        if(root->left!=nullptr)
            minDepthHelper(root->left, depth+1);
        if(root->right!=nullptr)
            minDepthHelper(root->right, depth+1);
    }
};

//Solution 2
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right)+1;
        if(!root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};
