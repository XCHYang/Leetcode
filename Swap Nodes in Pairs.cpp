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
    ListNode *swapPairs(ListNode *head) {
        ListNode* p = head;
        if(head == NULL|| head->next == NULL) return head;
        ListNode* q;
        head = head->next;
        p->next = head->next;
        head->next = p;
        while(p->next != NULL){
            if(p->next->next == NULL){
                return head;
            }
            else{
                q = p->next->next;
            }
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        return head;
    }
};
