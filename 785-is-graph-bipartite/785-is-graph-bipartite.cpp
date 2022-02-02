class Solution {
public:
    bool bfsbipartite(vector<vector<int>> &adj, vector<int> &color, int n, int p = -1){
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
    bool isBipartite(vector<vector<int>>& graph) {
        //vector<vector<int>> adj()
        vector<int> color(graph.size(),-1);
        cout << graph[0].size() << " ";
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1 && graph[i].size() != 0){
                if(!bfsbipartite(graph,color,i))
                    return false;
            }
        }
        return true;
    }
};