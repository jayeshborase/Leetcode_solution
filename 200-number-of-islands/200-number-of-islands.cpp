class Solution {
public:
    void dfs(vector<vector<char>> &ma, int i, int j, int r, int c){
        if(i < 0 || i >= r || j < 0 || j >= c || ma[i][j] != '1')
            return;
        
        ma[i][j] = '2';
        
        dfs(ma,i+1,j,r,c);
        dfs(ma,i,j+1,r,c);
        dfs(ma,i-1,j,r,c);
        dfs(ma,i,j-1,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int r = grid.size();
        if(r == 0)
            return 0;
        int c = grid[0].size();
        int no_of_island = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j,r,c);
                    no_of_island++;
                }
            }
        }
        
        return no_of_island;
    }
};