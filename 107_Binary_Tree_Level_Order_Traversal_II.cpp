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
    vector<vector<int>> ret;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        buildRet(root,0);
        return vector<vector<int>>(ret.rbegin(), ret.rend());
    }
    void buildRet(TreeNode *root, int depth){
        if(root==nullptr)
            return;
        if(ret.size()==depth)
            ret.push_back(vector<int>());
        ret[depth].push_back(root->val);
        buildRet(root->left, depth+1);
        buildRet(root->right, depth+1);
    }
};
