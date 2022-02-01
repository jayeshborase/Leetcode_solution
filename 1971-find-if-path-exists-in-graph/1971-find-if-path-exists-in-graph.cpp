class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vist, set<int> &ans){
        ans.insert(node);
        vist[node] = 1;
        
        for(auto i : adj[node]){
            if(!vist[i])
                dfs(i,adj,vist,ans);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> vist(n,0);

        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i = 0; i < n; i++){
            set<int> s;
            if(!vist[i]){
                dfs(i,adj,vist,s);
            }
            if(s.find(source) != s.end() && s.find(destination) != s.end())
                return true;
        }
        
        return false;
    }
};