/*
 *dp solution
 2018-12-31
 * */
class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        状态：a[i][j]，表示到a[i][j]的方法
        转移：a[i][j] = a[i-1][j] + a[i][j-1]
        */
        if(m < 1 || n < 1) {
            return 0;
        }
        if(m == 1 || n == 1) {
            return 1;
        }
        int a[m][n]={0};
        for(int i = 0; i < m; i++) {
            a[i][0] = 1;
        }
        for(int j = 0; j < n; j++) {
            a[0][j] = 1;
        }
        a[0][0] = 0;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[m-1][n-1];
    }
};


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
