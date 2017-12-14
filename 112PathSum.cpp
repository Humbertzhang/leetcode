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
    bool ret = false;
    bool hasPathSum(TreeNode* root, int sum) {
        ret = false;
        if(!root){
            return false;
        }
        int val = 0;
        pathsum(root, sum, val);
        return ret;
    }
    void pathsum(TreeNode* root, int sum, int val){
        if(root -> right==NULL && root -> left == NULL){
            if(val+root->val == sum){
                ret = true;
                return;
            }
        }
        if(root->right && ret == false){
            pathsum(root->right, sum, val + root -> val);
        }
        if(root->left && ret == false){
            pathsum(root->left, sum, val + root -> val);
        }
    }
};
