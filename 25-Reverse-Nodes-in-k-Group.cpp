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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head), *prev = dummy, *cur = head;
        while (true) {
            ListNode *temp = cur;
            int count = 0;
            while (temp && count < k) {
                temp = temp->next;
                count++;
            }
            if (count < k) break;
            ListNode *next = nullptr, *tail = cur;
            for (int i = 0; i < k; i++) {
                next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            tail->next = cur;
            prev = tail;
        }
        return dummy->next;
    }
};
