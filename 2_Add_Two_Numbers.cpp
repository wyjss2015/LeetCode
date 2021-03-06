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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0, tmp;
        ListNode *head;
        ListNode *p;
        p = head;
        if(l1 && l2){
            tmp = l1->val+l2->val+c;
            if(tmp>9) c = 1;
            else c = 0;
            head = l1;
            l1 = l1->next;
            l2 = l2->next;
            head->val = tmp%10;
            head->next = nullptr;
            p = head;
        }else if(l1)
            return l1;
        else
            return l2;
        while(l1 && l2){
            tmp = l1->val+l2->val+c;
            if(tmp>9) c = 1;
            else c = 0;
            p->next = l1;
            l1 = l1->next;
            l2 = l2->next;
            p->next->val = tmp%10;
            p->next->next = nullptr;
            p = p->next;
        }
        if(l1){
            while(l1 && c==1){
                tmp = l1->val + c;
                if(tmp>9) c = 1;
                else c = 0;
                p->next = l1;
                l1 = l1->next;
                p->next->val = tmp%10;
                p->next->next = nullptr;
                p = p->next;
            }
            if(l1){
                p->next = l1;
            }else if(c==1){
                p->next = new ListNode(1);
            }
        }
        if(l2){
            while(l2 && c==1){
                tmp = l2->val + c;
                if(tmp>9) c = 1;
                else c = 0;
                p->next = l2;
                l2 = l2->next;
                p->next->val = tmp%10;
                p->next->next = nullptr;
                p = p->next;
            }
            if(l2){
                p->next = l2;
            }else if(c==1){
                p->next = new ListNode(1);
            }
        }
        if(!l1&&!l2&&c==1){
            p->next = new ListNode(1);
        }
        return head;
    }
};

//Solution 2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *p;
        int c=0;
        head = new ListNode(0);
        p = head;
        while(l1||l2){
            if(l1){
                c += l1->val;
                l1 = l1->next;
            }
            if(l2){
                c += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(c%10);
            p = p->next;
            c /= 10;
        }
        if(c==1)
            p->next = new ListNode(c);
        return head->next;
    }
};
