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
        if (head == NULL) return false;
        ListNode* a = head;
        ListNode* b = head;
        while(b != NULL && b->next != NULL){
            b = b->next->next;
            a = a->next;
            if (a==b) return true; 
        }
        return false;
    }
};