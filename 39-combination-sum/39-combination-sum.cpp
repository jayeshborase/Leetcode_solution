class Solution {
public:
    void solve(vector<int>& can, vector<vector<int>>& v, vector<int> out, int in, int t){
        if(in == can.size()){
            if(t == 0)
                v.push_back(out);
            return;
        }
        if(can[in] <= t){
            out.push_back(can[in]);
            solve(can,v,out,in,t-can[in]);
            out.erase(out.end()-1);
        }
        solve(can,v,out,in+1,t);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> out;
        solve(candidates,v,out,0,target);
        return v;
    }
};