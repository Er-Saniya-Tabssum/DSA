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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        int size = 1;
        ListNode* temp = head;
        ListNode* perv = head;
        ListNode* per = head;
        while (temp->next != NULL) {
            size++;
            temp = temp->next;
        }
        int rotation = size - (k % size);
        if(k%size==0){
            return head;
        }
        ListNode* t = head;
        int cnt=1;
        while (t != NULL) {
            if(rotation==cnt){
                break;
            }
            cnt++;
            t=t->next;
        }

        temp->next= head;
        ListNode* res = t->next;
        t->next=NULL;
        return res;
    }
};