class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vist, int &s, int &d){
        //ans.insert(node);
        vist[node] = 1;
        s = (node == s) ? -1 : s;
        d = (node == d) ? -1 : d;
        for(auto i : adj[node]){
            if(!vist[i])
                dfs(i,adj,vist,s,d);
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
            //set<int> s;
            int s = source;
            int d = destination;
            if(!vist[i]){
                dfs(i,adj,vist,s,d);
            }
            // if(s.find(source) != s.end() && s.find(destination) != s.end())
            //     return true;
            if(s == -1 && d == -1)
                return true;
        }
        
        return false;
    }
};