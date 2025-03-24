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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp =  head;
        if(n == 1 && !head->next)return head->next;
        while(temp){
            len++;
            temp = temp->next;
        }
        len -= n;
        temp = head;
        if(len == 0)return head->next;
        while(len != 1){
            len--;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};