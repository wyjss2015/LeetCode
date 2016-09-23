#105. Construct Binary Tree from Preorder and Inorder Traversal
##Question
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

##Analysis
* 分治，递归

##Solution
```
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int psize = preorder.size();
        int isize = inorder.size();
        return helper(preorder, 0, psize-1, inorder, 0, isize-1);
    }
    TreeNode* helper(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        if(pl>pr) return nullptr;
        int rootVal = preorder[pl];
        int rootInIdx;
        for(int i=il;i<=ir;++i)
            if(inorder[i]==rootVal){
                rootInIdx = i;
                break;
            }
        TreeNode* leftTree = helper(preorder, pl+1, pl+rootInIdx-il, inorder, il, rootInIdx-1);
        TreeNode* rightTree = helper(preorder, pl+rootInIdx-il+1, pr, inorder, rootInIdx+1, ir);
        TreeNode* root = new TreeNode(rootVal);
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
};
```