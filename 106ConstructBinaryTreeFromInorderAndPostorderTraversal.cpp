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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() ==0) {
            return NULL;
        } else {
            return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        }
    }
    
    TreeNode* build(vector<int>& inorder, int inleft, int inright, vector<int>& postorder, int postleft, int postright) {
        if(inleft > inright || postleft > postright) {
            return NULL;
        }
        TreeNode* t = new TreeNode(postorder[postright]);
        for(int k = inleft; k <= inright; k++){
            if(inorder[k] == postorder[postright]) {
                t->left = build(inorder, inleft, k-1, postorder, postleft, postleft + k - inleft -1);
                t->right = build(inorder, k+1, inright, postorder, postleft+k-inleft, postright-1);
            }
        }
        return t;
    }
    
};
