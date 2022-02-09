class Solution {
public: 
    bool cyclebfs(int n, int p, vector<vector<int>> &adj, vector<int> &vist){
        queue<pair<int,int>> q;
        q.push({n,p});
        vist[n] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            
            for(auto i : adj[node]){
                if(!vist[i]){
                    q.push({i,node});
                    vist[i] = 1;
                }else if(i != prev){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        vector<int> vist(edges.size()+1);
        
        for(auto i : edges){
            fill(begin(vist),end(vist),0);
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            if(cyclebfs(i[0],-1,adj,vist)) return i;
        }
        
        return {};
        
        
    }
};