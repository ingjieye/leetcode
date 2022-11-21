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
        auto slow = head, fast = head;
        bool ret = false;
        while (fast) {
            if (!fast->next || !fast->next->next) break;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ret = true;
                break;
            }
        }
        return ret;
    }
};