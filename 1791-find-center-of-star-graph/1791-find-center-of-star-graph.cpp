class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
//         vector<vector<int>> adj(edges.size()+2);
        
//         for(auto i : edges){
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
        
//         int mx = 0;
//         int ans = 0;
        
//         for(int i = 1; i< adj.size(); i++){
//             if(mx < adj[i].size()){
//                 mx = adj[i].size();
//                 ans = i;
//             }
//         }
        
//         return ans;
        
        int a=edges[0][0],b=edges[0][1],ans=0;
        for(int i=1;i<edges.size();i++){
            //for(int j=1;j<edges[0].size();j++){
                if(edges[i][1]==a)
                    ans=a;
                else if(edges[i][1]==b)
                    ans=b;
                else
                    continue;
           // }
        }
        return ans;
    }
};