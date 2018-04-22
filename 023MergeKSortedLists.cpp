// 28ms Solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n <= 0){return NULL;}
        
        while(n > 1){
            int nextlen = (n+1)/2;
            for(int i = 0; i < n/2; i++){
                lists[i] = merge2Lists(lists[i], lists[i+nextlen]);
            }
            n = nextlen;
        }
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val >= l2->val){
                head -> next = l2;
                head = head->next;
                l2 = l2->next;
            }
            else{
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            }
        }
        if(l1 == NULL){
            head -> next = l2;
        }else{
            head -> next = l1;
        }
        return ret->next;
    }
};


//自己的垃圾算法 452ms
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        int size = lists.size();
        while(true){
            int minnum = 2147483647;
            int mini = 0;
            int stopflag = 1;
            for(int i = 0; i < size; i++){
                ListNode* temp = lists[i];
                if(temp != NULL){
                    stopflag = 0;
                    if(temp->val < minnum){
                        minnum = temp->val;
                        mini = i;
                    }
                }
            }
            if(stopflag){
                break;
            }
            ListNode* nextnode = new ListNode(minnum);
            head -> next = nextnode;
            head = head->next;
            lists[mini] = lists[mini] -> next;
            
        }
        
        return ret->next;
    }
};
