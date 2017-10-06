/**
用map来存放已经递归中之前计算过的东西
避免重复计算
不过他们都有0ms的Solution....
应该是用的数学的什么方法吧
*/
class Solution {
public:
    std::map<vector<int>, int> amap;

    int uniquePaths(int m, int n) {
        int ret = 0;
        if(m == 1 || n == 1)
            return 1;
        else{
            vector<int> a(2);
            a[0] = m;//vector来标识一个m,n组合
            a[1] = n;
            if(amap.find(a) != amap.end()){
                return amap[a];
            }
            else{
                ret += uniquePaths(m-1,n);
                ret += uniquePaths(m, n-1);
                amap[a] = ret;
                return ret;
            }
        }
    }
};
