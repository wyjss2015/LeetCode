/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre, *cur;
        if(head==nullptr)
            return nullptr;
        pre = cur = head;
        while(cur!=nullptr){
            if(cur->val==pre->val)
                cur = cur->next;
            else{
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        pre->next = nullptr;
        return head;
    }
};
