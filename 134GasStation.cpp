/*我的超时代码..158ms O(n^2)复杂度*/
//后来看Discuss,如果你不能从A到B，那么在A到B中的任何一个Gas station
//都不可能到达B
//根据这个提示，做了修改，就把时间降到6ms了...
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        if(size == 0){
            return -1;
        }
        else if(size == 1){
            if(gas[0] >= cost[0]){
                return 0;
            }else{
                return -1;
            }
        }
        for(int i = 0; i < size; i++){
            int tank = gas[i];
            for(int j = i; j < i + size; j++){
                tank -= cost[j%size];
                if(tank < 0){
					i = j //根据Discuss修改处
                    break;
                }
                tank += gas[(j+1)%size];
            }
            if(tank >= 0){
                return i;
            }
        }
        return -1;
    }
};
