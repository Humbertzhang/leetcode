/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//不同于002的地方是直接用的生成好了的节点而没有传递值
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val <= l2 ->val){
                ptr -> next = l1;
                l1 = l1 ->next;
            }
            else if(l2 -> val < l1 ->val){
                ptr ->next = l2;
                l2 = l2 ->next;
            }
            ptr = ptr -> next;
        }
        if(l1 != NULL)
            ptr -> next = l1;
        else
            ptr -> next = l2;
        return head->next;
    }
};
