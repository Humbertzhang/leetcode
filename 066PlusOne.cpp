/*3ms Solution, the best*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(size == 0)
            return digits;
        
        digits[size-1] += 1;
        for(int i = size-1; i>=0; i--){
            if(digits[i] >= 10){
                if(i == 0){
                    vector<int> newd(size + 1);
                    newd[0] = 1;
                    newd[1] = digits[i] - 10;
                    for(int j = 2; j <= size; j++){
                        newd[j] = digits[j-1];
                    }
                    return newd;
                }
                else{
                    digits[i-1] += 1;
                    digits[i] -= 10;
                }
            }
        }
        return digits;
    }
};
