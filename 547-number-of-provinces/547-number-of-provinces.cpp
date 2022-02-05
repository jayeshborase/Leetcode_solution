class Solution {
public:
    void dfs(vector<vector<int>> &ma, int r){
        
        for(int i = 0; i < ma.size(); i++){
            if(ma[r][i] == 1){
                ma[r][i] = 2;
                ma[i][r] = 2;
                dfs(ma,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int ans = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[i][i] == 1){
                ans++;
                dfs(isConnected,i);
            }
        }
        
        return ans;
    }
};