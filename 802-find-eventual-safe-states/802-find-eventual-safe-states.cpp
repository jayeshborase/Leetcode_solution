class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &out, vector<int> &safe, vector<int> &df){
        if(!safe[node]){
            return false;
        }
        if(!out[node]){
            safe[node] = 0;
            return false;
        }
        //if(out[node])
        out[node]--;
        df[node] = 1;
        
        for(auto i :adj[node]){
            if(df[i]){
                out[node]++;
                out[i]++;
                df[i] = 0;
                return true;
            }else if(dfs(i,adj,out,safe,df)){
                out[node]++;
                return true;
            }
            
        }
        df[node] = 0;
        safe[node] = 0;
        //out[node] = 
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //vector<vector<int>> adj(graph.size());
        //vector<int> vist(graph.size(),0);
        vector<int> dfvist(graph.size(),0);
        vector<int> safe(graph.size(),1);
        vector<int> out(graph.size(),0);
        
        for(int i = 0; i < graph.size(); i++){
            out[i] = graph[i].size();
        }
        
        vector<int> ans;
        for(int i = 0; i < graph.size(); i++){
            //fill(begin(vist), end(vist), 0);
            if(dfs(i,graph,out,safe,dfvist)){
                continue;
            }
            ans.push_back(i);
        }
        return ans;
    }
};