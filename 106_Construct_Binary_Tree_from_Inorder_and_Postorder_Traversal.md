#106. Construct Binary Tree from Inorder and Postorder Traversal
##Question
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

##Analysis

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int isize = inorder.size();
        int psize = postorder.size();
        return create(inorder, 0, isize-1, postorder, 0, psize-1);
    }
    TreeNode* create(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr){
        if(il>ir) return nullptr;
        int rootVal = postorder[pr];
        int rootInIdx;
        for(int i=il;i<=ir;++i)
            if(inorder[i] == rootVal) rootInIdx = i;
        TreeNode* leftTree = create(inorder, il, rootInIdx-1, postorder, pl, pl+rootInIdx-il-1);
        TreeNode* rightTree = create(inorder, rootInIdx+1, ir, postorder, pl+rootInIdx-il, pr-1);
        TreeNode* root = new TreeNode(rootVal);
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
};
```