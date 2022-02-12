class Solution {
public:
    int bina(int n,vector<int> &dp){
        int co = 0;
        while(n != 0){
            if(n&1){
               co++; 
            }
            if(dp[n>>1] != -1){
                dp[n] = co+dp[n>>1];
                return dp[n];
            }
            n = n>>1;
        }
        return co;
    }
    vector<int> countBits(int n) {
        vector<int> v(1,0);
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            v.push_back(bina(i,dp));
        }
        return v;
    }
};