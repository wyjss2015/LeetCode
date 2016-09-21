#61. Rotate List
##Question
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

##Analysis
* 思路： 利用两个指针，第一个指针比第二个指针提前k步，同步移动，当第一个指针到达末尾第一个指针正好指向倒数第k个节点的前继节点
* 各种情况：
	1. k == 0
	2. head == nullptr
	3. k<len
	4. k>len
	5. k==len

#Solution
```
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0) return head;
        ListNode *p, *q;
        p = q = head;
        int cnt = 0;
        for(int i=0;i<k;++i)
            if(q){
                ++cnt;
                q = q->next;
            }else break;
        cout << cnt << endl;
        if(!q&&cnt <= k){
            k %= cnt;
            q = head;
            for(int i=0;i<k;++i)
                q = q->next;
        }
        while(q&&q->next){
            p = p->next;
            q = q->next;
        }
        q->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
```