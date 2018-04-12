/*
因为为从小到大排列
选定一个数字i作为root之后，左孩子的可能出现的数字的数目即为
i-1(比其小的所有数字)， 右孩子可能出现的数字的数目即为n-i(比其
大的所有数字),他们的结果相乘即为i作为root时的结果，再将所有i的结果
加起来即为最终结果。
注意，为了避免重复计算，使用了一个record数组来记录numTrees[i]的结果.
*/

class Solution {
public:
    int record[10000];
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        int count = 0;
        for(int i = 1; i <= n; i++){
            int n1 = 0, n2 = 0;
            if(record[i-1] != 0){
                n1 = record[i-1];
            }else{
                n1 = numTrees(i-1);
                record[i-1] = n1;
            }
            
            if(record[n-i] != 0){
                n2 = record[n-i];
            }else{
                n2 = numTrees(n-i);
            }

            count += n1*n2;
            
        }
        return count;
    }
};
