class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // tail
        int index = digits.size() - 1;
        digits[index] += 1;
        if(digits[index] == 10) {
            while(index != 0) {
                if(digits[index] == 10) {
                    digits[index] -= 10;
                    digits[index-1] += 1;
                    index -= 1;
                }
                else {
                    return digits;
                }
            }
            // index == 0
            if(digits[index] == 10) {
                digits[index] -= 10;
                digits.insert(digits.begin(), 1);
            }
            return digits;
        } else {
            return digits;
        }
    }
};
