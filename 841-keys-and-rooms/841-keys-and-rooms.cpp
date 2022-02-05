class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vist, int &size){
        vist[node] = 1;
        
        for(auto i : adj[node]){
            if(!vist[i]){
                dfs(i,adj,vist,--size);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vist(rooms.size(), 0);
        int size = rooms.size();
        
        dfs(0,rooms,vist,--size);
        
        return size == 0;
    }
};