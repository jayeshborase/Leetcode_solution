class Solution {
public:
    bool winnerSquareGame(int n) {
         vector<bool>dp(n+1,false);
        if(n==1)
            return true;
        if(n==2)
            return false;
        dp[0]=false;
        dp[1]=true;
        dp[2]=false;
        for(int i=3;i<=n;i++)
        {
            for(int k=1;k*k<=i;k++)
            {
                dp[i]=dp[i]||!dp[i-k*k];
                if(dp[i])
                    break;
            }
        }
        return dp[n];
        
    }
};