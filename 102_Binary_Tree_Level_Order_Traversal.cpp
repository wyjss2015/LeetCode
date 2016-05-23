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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> a;
        vector<int> b;
        int bh;
        queue<TreeNode *> q;
        queue<int> qh;
        TreeNode *p;
        int ph;
        if(root == nullptr)
            return a;
        q.push(root);
        qh.push(1);
        while(!q.empty()){
            p = q.front();
            ph = qh.front();
            q.pop();
            qh.pop();
            if(p->left!=nullptr){
                q.push(p->left);
                qh.push(ph+1);
            }
            if(p->right!=nullptr){
                q.push(p->right);
                qh.push(ph+1);
            }
            if(b.empty())
                bh = ph;
            if(ph==bh)
                b.push_back(p->val);
            else{
                a.push_back(b);
                b.clear();
                bh = ph;
                b.push_back(p->val);
            }
        }
        if(!b.empty())
            a.push_back(b);
        return a;
    }
};

//Solution 2 preorder
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
        buildRet(root, 0);
        return ret;
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
