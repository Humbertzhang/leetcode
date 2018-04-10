class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.reserve(200);
        if(nums.size() <= 2){
            return ret;
        }
        
        int vsize = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < vsize-2; i++){
            //防止重复
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int a = nums[i];
            int start = i + 1;
            int end = vsize - 1;
            
            while(start < end){
                int b = nums[start];
                int c = nums[end];
                if(a + b + c == 0){
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    ret.push_back(v);
                    //以下代码为了防止重复
                    start+=1;
                    end -= 1;
                    while(nums[start] == nums[start-1]){
                        start += 1;
                    }
                    while(nums[end] == nums[end+1]){
                        end -= 1;
                    }
                }
                else if(a + b + c > 0){
                    end -= 1;
                }
                else{
                    start += 1;
                }
            }
        }
        //vector<vector<int>>::iterator it = unique(ret.begin(), ret.end());
        //ret.resize( distance(ret.begin(), it) );
        return ret;
    }
};
