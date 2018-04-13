class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        std::bitset<64> b1(x);
        std::bitset<64> b2(y);
        for(unsigned int i = 0; i < b1.size(); i++){
            if(b1[i] != b2[i]){
                count += 1;
            }
        }
        return count;
    }
};
