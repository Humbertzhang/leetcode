/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    stack <int> vecp;
    stack <int> vecq;
    
    void traversal(TreeNode* p, stack<int> * s) {
        if (p == NULL) {
            s->push(NULL);
            return;
        }
        s->push(p->val);
        traversal(p->left, s);
        traversal(p->right, s);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if((p == NULL && q != NULL) || (q == NULL && p != NULL))
            return false;
        
        stack<int> stackp;
        stack<int> stackq;
        traversal(p, &stackp);
        traversal(q, &stackq);
        
        if(stackp.size()!=stackq.size())
            return false;
        else{
            while(stackp.empty() != true) {
                if(stackp.top() != stackq.top())
                    return false;
                stackp.pop();
                stackq.pop();
            }
            return true;
        }
    }
    
};
