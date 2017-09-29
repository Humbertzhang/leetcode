/*
垃圾代码..
Your runtime beats 12.95 % of cpp submissions.
遍历了两次,链表，第一次求长度，第二次删除
应该有只遍历一次的解法
*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)   //输入为NULL
            return NULL;
        
        int listlen = 1;
        
        ListNode * ptr = head;
        ListNode * dummy = head;
        
        while(ptr->next != NULL){
            ptr = ptr->next;
            listlen+=1;
        }
        
        if(listlen == 1){   //只有一个Node
            return NULL;
        }
        
        if(n == listlen){   //删除头节点
            dummy = dummy -> next;
            return dummy;
        }
        
        //remove len - n + 1
        int i = 0;
        while(true){
            if(i == listlen - n - 1){
                if(dummy->next->next == NULL)
                    dummy->next = NULL;
                else
                    dummy -> next = dummy->next->next;
                break;
            }else{
                dummy = dummy->next;
                i += 1;
            }
        }
        return head;
    }
};
