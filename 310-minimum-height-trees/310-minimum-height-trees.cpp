class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1 && edges.size() == 0)
            return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < degree.size(); i++){
            if(degree[i] == 1)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int si = q.size();
            ans.clear();
            
            while(si--){
                int node = q.front();
                q.pop();
                
                ans.push_back(node);
                
                for(auto i : adj[node]){
                    degree[i]--;
                    if(degree[i] == 1)
                        q.push(i);
                }
            }
        }
        
        return ans;
    }
};