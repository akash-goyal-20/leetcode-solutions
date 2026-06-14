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
    vector<int> ans;
    void f(ListNode* head) {
        if (head == NULL) {
            return;
        }
        ans.push_back(head->val);
        f(head->next);
    }
    int pairSum(ListNode* head) {
        f(head);

        int i = 0;
        int j = ans.size() - 1;
        int maxi = INT_MIN;
        while (i < j) {
            maxi = max(maxi, ans[i] + ans[j]);
            i++;
            j--;
        }

        return maxi;
    }
};