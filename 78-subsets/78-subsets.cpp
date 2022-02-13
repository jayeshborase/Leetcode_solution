class Solution {
public:
    void solve(int n, vector<int> &nums, vector<vector<int>> &ans, vector<int> out){
        if(n == nums.size()){
            ans.push_back(out);
            return;
        }
        
        solve(n+1,nums,ans,out);
        
        out.push_back(nums[n]);
        
        solve(n+1,nums,ans,out);
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        
        solve(0,nums,ans,out);
        
        return ans;
    }
};