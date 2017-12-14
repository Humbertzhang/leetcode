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
    vector<vector<int>> ret;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ret.clear();
        ret.reserve(1000);
        
        if(!root){
            return ret;
        }
        
        int val = 0;
        vector<int> apath;
        apath.reserve(100);
        
        getpath(root, sum, val, apath);
        return ret;
    }
    void getpath(TreeNode* root, int sum, int val, vector<int> apath){
        vector<int> apath2 = apath;
        if(root->right == NULL && root->left == NULL){
            if(val + root->val == sum){
                apath.push_back(root->val);
                ret.push_back(apath);
                return;
            }
        }
        if(root->right){
            apath.push_back(root->val);
            getpath(root->right, sum, val+root->val, apath);
        }
        if(root->left){
            apath2.push_back(root->val);
            getpath(root->left, sum, val+root->val, apath2);
        }
    }
};
