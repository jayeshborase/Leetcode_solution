class Solution {
public:
    bool bfsbipartite(vector<vector<int>> &adj, vector<int> &color, int n){
        queue<int> q;
        q.push(n);
        color[n] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i : adj[node]){
                if(color[i] == -1){
                    q.push(i);
                    color[i] = !color[node];
                }else if(color[i] == color[node])
                    return false;
            }
        }
        
        return true;
    }
    
    bool dfsbipartite(vector<vector<int>> &adj, vector<int> &color, int n, int p = -1){
        if(color[n] == -1) 
            color[n] = 1;
        
        for(auto i : adj[n]){
            if(color[i] == -1){
                color[i] = !color[n];
                if(!dfsbipartite(adj,color,i,n))
                    return false;
            } else if(color[i] == color[n])
                    return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
     
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1 && graph[i].size() != 0){
                if(!dfsbipartite(graph,color,i))
                    return false;
            }
        }
        
        return true;
    }
};