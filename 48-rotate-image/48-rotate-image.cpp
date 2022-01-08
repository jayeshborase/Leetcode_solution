class Solution {
public:
    void rotate(vector<vector<int>>& ma) {
        int n = ma.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(ma[i][j], ma[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(ma[i].begin(), ma[i].end());
        }
    }
};