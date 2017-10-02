/*runtime only beats 28%, But the approach is same*/
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        else{
            ListNode * temp1 = new ListNode(0);
            temp1->val = head->val;
            temp1->next = head->next;
            ListNode * temp2 = new ListNode(0);
            temp2->val = head->next->val;
            temp2->next = head->next->next;
            
            head->val = temp2->val;
            head->next = temp1->next;
            head->next->val = temp1->val;
            head->next->next = temp2->next;
            
            head->next->next = swapPairs(temp2->next);

            return head;
        }
    }
};
