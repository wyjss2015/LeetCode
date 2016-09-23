#117. Populating Next Right Pointers in Each Node II
##Question
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

* You may only use constant extra space.

For example,
Given the following binary tree,
```
         1
       /  \
      2    3
     / \    \
    4   5    7
```
After calling your function, the tree should look like:
```
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
```

##Analysis
* BFS (using queue)
* 不用队列的层次遍历： 【[链接](https://discuss.leetcode.com/topic/1106/o-1-space-o-n-complexity-iterative-solution)】
	* 维护3个指针:head, pre, cur
	* head: 下一层的第一个节点
	* pre: 下一层最近处理过的节点
	* cur: 当前层孩子节点正在被处理的节点，即pre的父母节点或pre的父母节点的next指向的节点

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
        if(!root) return;
        queue<TreeLinkNode*> que1;
        queue<int> que2;
        que1.push(root);
        que2.push(1);
        while(!que1.empty()){
            TreeLinkNode *temp = que1.front();
            que1.pop();
            int level = que2.front();
            que2.pop();
            if(que1.empty()||que2.front()!=level) temp->next = nullptr;
            else temp->next = que1.front();
            if(temp->left){
                que1.push(temp->left);
                que2.push(level+1);
            }
            if(temp->right){
                que1.push(temp->right);
                que2.push(level+1);
            }
        }
    }
};
```