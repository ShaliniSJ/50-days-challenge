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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto l:lists){
            for(l;l;l = l->next)pq.push(l->val);
        }
        ListNode* head = new ListNode(0);
        for(ListNode* ite = head; !pq.empty(); ite = ite->next ){
            ite->next = new ListNode(pq.top());
            pq.pop();
        }
        return head->next;
    }
};