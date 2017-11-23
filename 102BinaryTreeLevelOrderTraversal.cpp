/**
主要思路为使用deque,在deque仅剩null时代表遍历完了，否则
从queue中拿出最前面那个元素，判断是否为NULL,为NULL则直接pop()，并在
队列尾部追加两个NULL作为NULL的leftchild, rightchild..(这也是最后爆时间的原因
如果是一个只有左树的树的话，会有大量时间空间的浪费 )
若不是NULL,则将其值加入到vector中，并将其leftchild, rightchild加入到队列最后

34个测试样例卡在最后那个爆时间了...方法应该没错，但是太低效了

之后换了下思路，用一个nnext来记录到底加了多少在队列中，然后每次从队列中拿出
这些元素作为一层的元素。之后就过了，并且时间是3ms，是最快.
*/



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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL){
            return ret;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        int next = 1;
        while(1){
            vector<int> v;
            int cflag = 0;
            int nnext = 0;
            int qsize = q.size();
            
            for(int i = 0; i < qsize; i++){
                if(q[i] != NULL){
                    cflag = 1;
                    break;
                }
            }
            
            if(cflag == 1){
                for(int i = 0; i < next; i++){
                    TreeNode * f = q.front(); 
                    if(f != NULL){
                        v.push_back(f->val);
                        q.pop_front();
                        q.push_back(f->left);
                        q.push_back(f->right);
                        nnext += 2;
                    }else{
                        q.pop_front();
                    }
                }
            }else{
                break;
            }
            
            ret.push_back(v);
            next = nnext;
        }
        return ret;
    }
};





class BadSolution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL){
            return ret;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        int step = 1;
        while(step){
            vector<int> v;
            int cflag = 0;
            for(int i = 0; i < q.size(); i++){
                if(q[i] != NULL){
                    cflag = 1;
                    break;
                }
            }
            if(cflag == 1){
                for(int i = 0; i < step; i++){
                    TreeNode * f = q.front(); 
                    if(f != NULL){
                        v.push_back(f->val);
                        q.pop_front();
                        q.push_back(f->left);
                        q.push_back(f->right);
                    }else{
                        q.pop_front();
                        q.push_back(NULL);
                        q.push_back(NULL);
                        continue;
                    }
                }
            }else{
                break;
            }
            ret.push_back(v);
            step *= 2;
        }
        return ret;
    }
};
