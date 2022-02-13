class Solution {
public:
    int jump(vector<int> &nums, int in, vector<int> &dp){  
        if(in == nums.size()-1){
            dp[in] = 1;
            return dp[in];
        }
        
         if(nums[in] == 0){
            dp[in] = 0;
            return dp[in];
         }
        
        if(dp[in] != -1)
            return dp[in];
        
        for(int i = in+1; i <= in+nums[in]; i++){
            if(jump(nums,i,dp)){
                dp[i-1] = 1;
                return dp[i-1];
            }
        }
        
        dp[in] = 0;
        return dp[in];
        
    }
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        
        vector<int> dp(nums.size(),-1);
        
        return jump(nums,0,dp);
    }
};