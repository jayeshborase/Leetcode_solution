class Solution {
public:
    void dfs(int n, int d,vector<vector<int>> &adj, vector<vector<int>> &ans, vector<int> path){
        path.push_back(n);
        if(n == d)
            ans.push_back(path);
        
        for(auto i : adj[n]){
            dfs(i,d,adj,ans,path);
            cout << path.size() << " ";
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> v;
     
        dfs(0,graph.size()-1,graph,v,{});
      
        return v;
    }
};