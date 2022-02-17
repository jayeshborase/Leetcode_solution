class Solution {
public:
    int maxAmt(vector<int> &nums, vector<int> &dp, int in){
        if(in == 0)
            return nums[0];
        
        if(in < 0)
            return 0;
        
        if(dp[in] != -1)
            return dp[in];
        
        int pick = nums[in] + maxAmt(nums,dp,in-2);
        int nonpick = 0 + maxAmt(nums,dp,in-1);

        return dp[in] = max(pick,nonpick);
    }
    int rob(vector<int>& nums) {
        int si = nums.size();
        vector<int> dp(si,-1);
        dp[0] = nums[0];
        int maxAmt = 0;
        for(int i = 1; i < si; i++){
            int pick = 0, nonPick = 0;
            
            pick = nums[i] + (i > 1 ? dp[i-2] : 0);
            
            nonPick = 0 + dp[i-1];
            
            dp[i] = max(pick, nonPick);   
        }
        return dp[si-1];//maxAmt(nums,dp,si-1);
    }
};