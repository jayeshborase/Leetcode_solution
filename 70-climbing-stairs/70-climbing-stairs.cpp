class Solution {
public:
    int climb(int n, vector<int> &dp){
        if(n <= 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = climb(n-1,dp) + climb(n-2,dp);
        
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,1);
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};