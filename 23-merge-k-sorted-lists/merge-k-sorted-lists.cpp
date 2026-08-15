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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp != NULL) {
                pq.push({temp->val, temp});
                temp = temp->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        while (!pq.empty()) {
            ListNode* curr = pq.top().second;
            pq.pop();

            prev->next = curr;
            prev = curr;
        }
        return dummy->next;
    }
};