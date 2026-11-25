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
    void reverselistk(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (k--) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        ListNode* left = head;
        ListNode* preleft = NULL;
        ListNode* res = NULL;
        ListNode* right;
        while (true) {
            right = left;
            for (int i = 0; i < k - 1; i++) {
                if (right == NULL)
                    break;
                right = right->next;
            }
            if (right) {
                ListNode* nextleft = right->next;
                reverselistk(left, k);
                if (preleft) {
                    preleft->next = right;
                }
                    preleft = left;
                if (res == NULL) {
                    res = right;
                }
                left = nextleft;
            } else {
                if (preleft) {
                    preleft->next = left;
                }
                if (res == NULL) {
                    res = left;
                }
                break;
            }
        }
        return res;
    }
};