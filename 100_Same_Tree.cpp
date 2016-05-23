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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (p!=nullptr&&q!=nullptr&&p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right))||(p==nullptr&&q==nullptr);
    }
};
