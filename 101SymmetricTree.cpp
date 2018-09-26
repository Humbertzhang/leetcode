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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
    bool isMirror(TreeNode * t1, TreeNode * t2) {
        if (t1 == NULL && t2 == NULL){
            return true;
        }
        else if (t1 == NULL || t2 == NULL) {
            return false;
        }
        else{
            return (t1->val == t2 -> val) && isMirror(t1->left, t2 -> right) && isMirror(t1 -> right, t2 -> left);
        }
    }
};



/*Solution at 2018-9-26  the fastest*/
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }   
        if (root->right == NULL && root->left == NULL){
            return true;
        }
        else if (root->right != NULL && root->right != NULL) {
            return judge(root->left, root->right);
        }
        else {
            return false;
        }
    }
    
    bool judge(TreeNode* leftnode, TreeNode* rightnode) {
        if(leftnode == NULL && rightnode == NULL) {
            return true;
        }
        else if (leftnode != NULL && rightnode != NULL) {
            if (leftnode->val == rightnode->val) {
                bool ret = judge(leftnode->left, rightnode->right);
                if(ret) {
                    return judge(leftnode->right, rightnode->left);
                } else {
                    return ret;
                }
            } else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};
