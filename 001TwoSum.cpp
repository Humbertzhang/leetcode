My Submission 186ms:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++)
                if (nums[i] + nums[j] == target && i!=j){
                    vector<int> ret(2);
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
            }
        }
    }
};

Other Sunmission 9ms:

#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int> op;
        map<int, int> h; 
        for(int i=0;i<num.size();i++)
        {
            
            if(h.find(target-num[i])!=h.end())	//如果找得到[target-num[i]]元素在h里面
            {    
                if(h[target-num[i]]!=i)			//并且不是本身
                {
                    op.push_back(h[target-num[i]]);
                    op.push_back(i);
                    return op;
                }
            } 
            h[num[i]]=i;	//用值当key,index当value.
        }
    }
};
