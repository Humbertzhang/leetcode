/*O(n)的解法，没想到只打败了30%的人*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //将两个合并为一个有序数组.
        vector<double> ret;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            double temp = nums1[i] < nums2[j]?nums1[i++]:nums2[j++];
            ret.push_back(temp);
        }
        while(i < nums1.size())
            ret.push_back(nums1[i++]);
        while(j < nums2.size())
            ret.push_back(nums2[j++]);
		/*上面为将两个数组合并为一个有序数组的O(n)算法*/
        double r;
        if(ret.size()%2 == 0)
            r = double( ( ret[ ret.size()/2 ] + ret[ ret.size()/2 - 1 ] ) /2 );
        else
            r = double(ret[ret.size()/2]);
        
        return r;
    }
};
