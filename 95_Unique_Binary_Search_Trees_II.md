#95. Unique Binary Search Trees II
##Question
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.
```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

##Analysis
* DP

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
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nodes(n+1);
        for(int i=0;i<=n;++i)
            nodes[i] = i;
        return helper(nodes, 1, n);
    }
    vector<TreeNode*> helper(vector<int> &nodes, int l, int r){
        if(l>r) return vector<TreeNode*>();
        else if(l==r){
            auto tn = new TreeNode(nodes[l]);
            return vector<TreeNode*>(1,tn);
        }
        
        auto trees = vector<TreeNode*>();
        for(int i=l;i<=r;++i){
            vector<TreeNode*> left = helper(nodes, l, i-1);
            vector<TreeNode*> right = helper(nodes, i+1, r);
            if(left.size()==0){
                for(auto temp: right){
                    auto root = new TreeNode(nodes[i]);
                    root->left = nullptr;
                    root->right = temp;
                    trees.push_back(root);
                }
            }else if(right.size()==0){
                for(auto temp: left){
                    auto root = new TreeNode(nodes[i]);
                    root->right = nullptr;
                    root->left = temp;
                    trees.push_back(root);
                }
            }else{
                for(auto temp: left){
                    for(auto temp1: right){
                        auto root = new TreeNode(nodes[i]);
                        root->left = temp;
                        root->right = temp1;
                        trees.push_back(root);
                    }
                }
            }
        }
        return trees;
    }
};
```