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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result, *p;
        if(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                result = l1;
                l1 = l1->next;
            }else{
                result = l2;
                l2 = l2->next;
            }
        }else if(l1!=nullptr){
            result = l1;
            l1 = l1->next;
        }else if(l2!=nullptr){
            result = l2;
            l2 = l2->next;
        }else
            return nullptr;
        p = result;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1!=0)
            p->next = l1;
        if(l2!=0)
            p->next = l2;
        return result;
    }
};




//Solution 2
ListNode * mergeTwoLists( ListNode * l1, ListNode * l2 )
{
    if( !l1 ) return l2;
    if( !l2 ) return l1;

    if( l1->val < l2->val )
    { 
        l1->next = mergeTwoLists( l1->next, l2 );
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists( l1, l2->next );
        return l2;
    }
}
