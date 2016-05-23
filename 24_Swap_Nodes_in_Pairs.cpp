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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p, *q, *pre;
        p = head;
        if(p){
            if((q=p->next)!=nullptr){
                p->next = q->next;
                q->next = p;
                head = q;
                pre = p;
                p = p->next;
            }else
                return head;
        }
        while(p){
            if((q=p->next)!=nullptr){
                p->next = q->next;
                q->next = p;
                pre->next = q;
                pre = p;
                p = p->next;
            }else
                break;
        }
        return head;
    }
};
