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
    int depth;
    int max;
    int maxDepth(TreeNode* root) {
        getdepth(root);
        return max;
    }
    void getdepth(TreeNode * root) {
        depth += 1;
        if(root == NULL) {
            depth --;
            return;
        }
        if(max < depth)
            max = depth;
        getdepth(root->left);
        getdepth(root->right);
        depth --;
        return;
    }
};
