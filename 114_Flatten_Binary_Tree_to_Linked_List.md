#114. Flatten Binary Tree to Linked List
##Question
Given a binary tree, flatten it to a linked list in-place.

For example,
Given
```
         1
        / \
       2   5
      / \   \
     3   4   6

```
The flattened tree should look like:
```
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
```
Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

##Analysis
* 观察实例容易看出:
	1. root->right = root->left
	2. root->left = nullptr
	3. flatten(root->left)的尾指针指向root->right
* **算法: **遍历树的最右边，如果当前点存在左孩子，对该左子树递归调用helper()进行flatten处理，将处理完的左子树嵌如右侧(因为要嵌入所以helper函数返回flatten完的左子树的末尾节点指针)。

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
    void flatten(TreeNode* root) {
        helper(root);
    }
    //return tail pointer
    TreeNode* helper(TreeNode* root){
        if(root == nullptr) return nullptr;
        TreeNode* temp = root;
        while(temp){
            if(temp->left){
                TreeNode* q = temp->left;
                temp->left = nullptr;
                TreeNode* tail = helper(q);
                if(tail){
                    tail->right = temp->right;
                    temp->right = q;
                }
            }
            temp = temp->right;
        }
        TreeNode* p = root;
        while(p->right)
            p = p->right;
        return p;
    }
};
```