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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL){
            return NULL;
        } 
        
        TreeNode * result1 = pruneTree(root->left);
        if(result1 == NULL){
            root->left = result1;
        }
        TreeNode * result2 = pruneTree(root->right);        
        if(result2 == NULL){
            root->right = result2;
        }
        if(root->left == NULL && root -> right == NULL){
            if(root->val == 0){
                return NULL;
            } else {
                return root;
            }
        }
        return root;
    }
};
