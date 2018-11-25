class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int il = 0;
        int ir = numbers.size()-1;
        while(il < ir) {
            if(numbers[il] + numbers[ir] < target) {
                il += 1;
            }
            else if(numbers[il] + numbers[ir] > target) {
                ir -= 1;
            }
            else {
                break;
            }
        }
        vector<int> v;
        v.push_back(il+1);
        v.push_back(ir+1);
        return v;
    }
};
