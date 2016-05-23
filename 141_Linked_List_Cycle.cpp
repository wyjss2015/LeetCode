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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode *faster, *slower;
        faster = slower = head;
        while(faster->next && faster->next->next){
            faster = faster->next->next;
            slower = slower->next;
            if(faster == slower) return true;
        }
        return false;
    }
};
