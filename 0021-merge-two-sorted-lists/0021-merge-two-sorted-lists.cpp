/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1 , *p2 = l2;
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        while(p1 && p2){
            if(p1->val > p2->val){
                dummy->next = p2;
                p2 = p2->next;
            }
            else {
                dummy->next = p1;
                p1 = p1->next;
            }
            dummy = dummy->next;
        }
        while(p1){
            dummy->next = p1;
            p1 = p1->next;
            dummy = dummy->next;
        }
        while(p2){
            dummy->next = p2;
            p2 = p2->next;
            dummy = dummy->next;
        }
        return res->next;
    }
};