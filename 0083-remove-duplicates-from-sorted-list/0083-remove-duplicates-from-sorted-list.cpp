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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *i=head;
        ListNode *j=head;
        if(head==NULL) return head;
        while(j->next!=NULL){
            if(i->val == j->next->val){
                j->next=j->next->next;
            }
            else{
                j=j->next;
                i=i->next;
            }
        }
        i->next=NULL;
        
        return head;
    }
};