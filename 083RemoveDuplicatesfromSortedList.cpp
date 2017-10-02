/*Beats 56%*/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* ptr = head;
        while(head->next != NULL){
            if(head->val == head->next->val)
                head->next = head->next->next;
            if(head->next != NULL && head->val != head->next->val){
                head = head->next;
            }
        }
        return ptr;
    }
};
