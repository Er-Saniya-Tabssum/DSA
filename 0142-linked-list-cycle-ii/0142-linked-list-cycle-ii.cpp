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
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* i = head;
        ListNode* j = head;
        while (j && j->next) {
            i = i->next;
            j = j->next->next;
            if (i == j)
                break;
        }
        if (!(j && j->next))
            return NULL;
        while (head != i) {
            head = head->next;
            i = i->next;
        }
        return head;
    }
};