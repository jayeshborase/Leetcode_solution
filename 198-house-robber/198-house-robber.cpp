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
        //vector<int> dp(si,-1);
        //dp[0] = nums[0];
        int pre1 = nums[0], pre2 = 0;
        int maxAmt = nums[0];
        for(int i = 1; i < si; i++){
            
            int pick = nums[i] + (i > 1 ? pre2 : 0); 
            int nonPick = 0 + pre1;
            
            maxAmt = max(pick, nonPick); 
            
            pre2 = pre1;
            pre1 = maxAmt;
        }
        return maxAmt;//dp[si-1];//maxAmt(nums,dp,si-1);
    }
};