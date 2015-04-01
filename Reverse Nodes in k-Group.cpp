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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k < 2) return head;
        ListNode* p = new ListNode(1);
        p->next = head;
        head = p;
        ListNode *q, *a, *b, *c;
        while(p->next != NULL){
            q = p->next;
            for(int i = 1; i < k; i++){
                if(q->next == NULL){
                    head = head->next;
                    return head;
                }
                else{
                    q = q->next;
                }
            }
            a = p->next;
            b = a->next;
            c = b->next;
            p->next = q;
            a->next = q->next;
            p = a;
            
            while(b != q){
                b->next = a;
                a = b;
                b = c;
                c = c->next;
            }
            b->next = a;
        }
        head = head->next;
        return head;
    }
};
