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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur, *pre;
        cur = pre = head;
        int i=0;
        while(i++<n)
            cur = cur->next;
        while(cur!=nullptr&&cur->next!=nullptr){
            cur = cur->next;
            pre = pre->next;
        }
        if(cur==nullptr)
            return head->next;
        else{
            pre->next = pre->next->next;
            return head;
        }
    }
};
