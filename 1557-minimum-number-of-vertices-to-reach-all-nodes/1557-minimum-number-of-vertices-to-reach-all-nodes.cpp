class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                ans.push_back(i);
        }
        return ans;
        //map<int,vector<int>> m;
        
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
            
//             vector<int> temp;
            
//             for(auto i : adj[node]){
//                 temp.push_back(i);
//                 indegree[i]--;
//                 if(indegree[i] == 0)
//                     q.push(i);
//             }
            
//             m.
//         }
    }
};