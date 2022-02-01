class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+2);
        
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int mx = 0;
        int ans = 0;
        
        for(int i = 1; i< adj.size(); i++){
            if(mx < adj[i].size()){
                mx = adj[i].size();
                ans = i;
            }
        }
        
        return ans;
    }
};