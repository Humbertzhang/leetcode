/*
曼哈顿距离(坐标绝对值)比所有ghosts短即可.
*/
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int gdis = 0;
        int mydis = getdis(0, 0, target[0], target[1]);
        for(int i = 0; i < ghosts.size(); i++){
            gdis = getdis(ghosts[i][0], ghosts[i][1], target[0], target[1]);
            if(gdis <= mydis) {
                return false;
            }
        }
        return true;
    }
    
    int getdis(int pox, int poy, int tarx, int tary) {
        return abs(pox-tarx) + abs(poy-tary);
    }
};
