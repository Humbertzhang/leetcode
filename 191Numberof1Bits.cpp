class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count1 = 0;
        for(int i = 0; i < 32; i++){
            if(n & 1 == 1){
                count1+=1;
            }
            n >>= 1;
        }
        return count1;
    }
};
