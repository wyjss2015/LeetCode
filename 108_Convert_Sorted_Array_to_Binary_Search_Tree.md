#108. Convert Sorted Array to Binary Search Tree
##Question
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return create(nums, 0, size-1);
    }
    TreeNode* create(vector<int>& nums, int l, int r){
        if(l>r) return nullptr;
        int mid = (l+r)/2;
        int rootVal = nums[mid];
        TreeNode* root = new TreeNode(rootVal);
        root->left = create(nums, l, mid-1);
        root->right = create(nums, mid+1, r);
        return root;
    }
};
```