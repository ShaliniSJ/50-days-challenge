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
    void reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr, *curr = start, *next = nullptr;
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        ListNode* start = prev->next;
        ListNode* end = start;
        for (int i = left; i < right; i++) {
            end = end->next;
        }
        ListNode* next = end->next;
        reverse(start, end);
        prev->next = end;
        start->next = next;
        return dummy.next;
    }
};