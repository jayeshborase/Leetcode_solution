class Solution {
public:
    int maxAmtdp(vector<int> &nums, vector<int> &dp, int in){
        if(in == 0)
            return nums[0];
        
        if(in < 0)
            return 0;
        
        if(dp[in] != -1)
            return dp[in];
        
        int pick = nums[in] + maxAmtdp(nums,dp,in-2);
        int nonpick = 0 + maxAmtdp(nums,dp,in-1);

        return dp[in] = max(pick,nonpick);
    }
    
    int maxAmttabu(vector<int> &nums, int in){
        vector<int> dp(in,-1);
        dp[0] = nums[0];
        
        for(int i = 1; i < in; i++){
            
            int pick = nums[i] + (i > 1 ? dp[i-2] : 0); 
            int nonPick = 0 + dp[i-1];
            
            dp[i] = max(pick, nonPick); 
        }
        
        return dp[in-1];
    }
    
     int maxAmtspac(vector<int> &nums, int in){
        int pre1 = nums[0], pre2 = 0;
        int maxAmt = nums[0];

        for(int i = 1; i < in; i++){
            
            int pick = nums[i] + pre2; 
            int nonPick = 0 + pre1;
            
            maxAmt = max(pick, nonPick); 
            
            pre2 = pre1;
            pre1 = maxAmt;
        }
        
        return maxAmt;
    }
    int rob(vector<int>& nums) {
        int si = nums.size();
        
        //return maxAmtdp(nums,dp,si-1);  
        //return maxAmttapu(nums,si);
        return maxAmtspac(nums,si);
    }
};