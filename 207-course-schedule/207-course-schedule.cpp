class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vist, vector<int> &df){
        vist[node] = 1;
        df[node] = 1;
        
        for(auto i : adj[node]){
            if(!vist[i]){
                if(dfs(i,adj,vist,df))
                    return true;
            }else if(df[i])
                return true;
        }
        df[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vist(numCourses,0);
        vector<int> df(numCourses,0);
        
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(!vist[i]){
                if(dfs(i,adj,vist,df))
                    return false;
            }
        }
        return true;
    }
};