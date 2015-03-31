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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        ListNode* p_pre = NULL;
        for(int i = 1; i < n; i++){
            q = q->next;
        }
        while(q->next != NULL){
            p_pre = p;
            p = p->next;
            q = q->next;
        }
        if(p_pre == NULL){
            head = head->next;
            return head;
        }
        p_pre->next = p->next;
        return head;
    }
};
