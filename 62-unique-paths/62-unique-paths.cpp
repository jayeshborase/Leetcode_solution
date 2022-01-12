class Solution {
public:
    int solve(int r, int c, int m, int n){
        if(r == m || c == n)
            return 0;
        if(r == m-1 && c == n-1)
            return 1;
        
        return solve(r,c+1,m,n) + solve(r+1,c,m,n);
    }
    int uniquePaths(int m, int n) {
        //return solve(0,0,m,n);
        
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};