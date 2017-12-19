//My solution
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
        multiset<ListNode *> visited;
        ListNode * ptr = head;
        while(head){
            if(visited.count(head) >= 1){
                return true;
            }
            visited.insert(head);
            head = head -> next;
        }
        return false;
    }
};


//The best solution

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
        if(head == NULL || head -> next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head -> next -> next;
        while(fast != NULL && fast -> next != NULL) {
            if(fast == slow){
                return true;
            }
            slow = slow->next;
            fast = fast -> next -> next;
        }
        return false;
    }
};
