#109. Convert Sorted List to Binary Search Tree
##Question
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

##Analysis
* 注意中点的选择: mid = len/2+1;

##Solution
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p){
            p = p->next;
            len++;
        }
        return create(head, len);
    }
    TreeNode* create(ListNode* head, int len){
        if(len<1) return nullptr;
        int mid = len/2+1;
        ListNode* p = head;
        int cnt = 1;
        while(cnt<mid){
            p = p->next;
            ++cnt;
        }
        int rootVal = p->val;
        TreeNode* root = new TreeNode(rootVal);
        root->left = create(head, mid-1);
        root->right = create(p->next, len-mid);
        return root;
    }
};
```