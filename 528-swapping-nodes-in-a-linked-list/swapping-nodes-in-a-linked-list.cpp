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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = NULL;
        ListNode* second = NULL;

        ListNode* temp = head;
        int cnt = 0;

        while (temp != NULL) {
            cnt++;
            if (cnt == k) {
                first = temp;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if (cnt == k) {
                second = temp;
            }
            temp = temp->next;
            cnt--;
        }
        swap(first->val, second->val);
        return head;
    }
};