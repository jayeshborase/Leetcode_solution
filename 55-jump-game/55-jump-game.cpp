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
                dp[in] = 1;
                return dp[in];
            }
        }
        
        dp[in] = 0;
        return dp[in];
        
    }
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        
        vector<int> dp(nums.size()+1,-1);
//         dp[0] = 1;
//         for(int i = 0; i < nums.size()-1; i++){
//             for(int j = i+1;  j <= i+nums[i]; j++){
//                 if(j < nums.size() && dp[j-1]){
//                     dp[j] = 1; 
//                     //break;
//                 }
                    
//             }
//         }
        
        return jump(nums,0,dp);//dp[nums.size()-1];//jump(nums,0,dp);
    }
};