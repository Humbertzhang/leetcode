class Solution {
public:
    vector<int> partitionLabels(string S) {
        int cmap[26] = {0};
        vector<int> v(0);
        /*记录每个字符最后一个位置*/
        for(int i = 0; i < S.size(); i++){
            cmap[S[i]-'a'] = i;
        }
        int start = 0;
        int end = 0;
        for(int i = 0; i < S.size(); i++) {
            end = max(end, cmap[S[i]-'a']);
            if(end == i) {
                int length = i - start + 1;
                start = i + 1;
                v.push_back(length);
            }
        }
        return v;
    }
};
