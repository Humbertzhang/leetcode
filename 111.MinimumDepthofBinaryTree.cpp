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
    int min = 10000;
    int minDepth(TreeNode* root) {
        min = 10000;
        if(!root){
            return 0;
        }
        int depth = 1;
        getmin(root, depth);
        return min;
    }
    void getmin(TreeNode* root, int depth){
        if(root->left == NULL && root->right == NULL){
            if(depth < min){
                min = depth;
                return;
            }
        }
        if(root->left){
            getmin(root->left, depth + 1);
        }
        if(root->right){
            getmin(root->right, depth + 1);
        }
    }
};
