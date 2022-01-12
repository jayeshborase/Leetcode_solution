class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        in.push_back(newIn);
        
        sort(in.begin(),in.end());
       
        vector<vector<int>> ans;
        
        for(int i = 0; i < in.size(); i++){
            int left = in[i][0];
            int right = in[i][1];
            
            while(i < in.size()-1 && right >= in[i+1][0]){
                right = max(right,in[i+1][1]);
                i++;
            }
            ans.push_back({left,right});
        }
        
        return ans;
    }
};