#116. Populating Next Right Pointers in Each Node
##Question
Given a binary tree
```
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
```
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
```
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
```
After calling your function, the tree should look like:
```
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
```

##Analysis
* 前序遍历
* 每次连接被当前的root分割开的部分

##Solution
```
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        helper(root);
        TreeLinkNode *p=root;
        while(p){
            p->next = nullptr;
            p = p->right;
        }
    }
    void helper(TreeLinkNode *root){
        if(!root||(!root->left&&!root->right)) return;
        TreeLinkNode *p = root->left, *q = root->right;
        while(p&&q){
            p->next = q;
            p = p->right;
            q = q->left;
        }
        helper(root->left);
        helper(root->right);
    }
};
```