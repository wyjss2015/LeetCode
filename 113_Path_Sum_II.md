#113. Path Sum II
##Question
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
```
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
```
return
```
[
   [5,4,11,2],
   [5,8,4,5]
]
```
##Analysis
* backtracking

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> allPaths;
        vector<int> path;
        helper(root, allPaths, path, sum);
        return allPaths;
    }
    void helper(TreeNode* root, vector<vector<int>>& allPaths, vector<int>& path, int sum){
        if(!root) return;
        if(!(root->left)&&!(root->right)&&sum==root->val){
            path.push_back(root->val);
            allPaths.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        helper(root->left, allPaths, path, sum-root->val);
        helper(root->right, allPaths, path, sum-root->val);
        path.pop_back();
    }
};
```