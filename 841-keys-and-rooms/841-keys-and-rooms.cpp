class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vist){
        vist[node] = 1;
        
        for(auto i : adj[node]){
            if(!vist[i]){
                dfs(i,adj,vist);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vist(rooms.size(), 0);
        
        dfs(0,rooms,vist);
        
        for(auto i : vist){
            if(i == 0)
                return false;
        }
        
        return true;
    }
};