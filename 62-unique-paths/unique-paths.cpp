class Solution {
public:

    int recPath(int cm, int cn, int m, int n, vector<vector<int>>&dp){
        if (cm >= m || cn >= n) return 0;
        if(cm==m-1 && cn==n-1){
            return 1;
        }
        if(dp[cm][cn] != -1) return dp[cm][cn];

        int right = recPath(cm,cn+1,m,n,dp);
        int down = recPath(cm+1,cn,m,n,dp);
        return dp[cm][cn] = right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
         int ans = recPath(0,0,m,n,dp);
         return ans;
    }
};