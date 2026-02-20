class Solution {
public:
vector<int>dp = vector<int>(46,-1);
    int climbStairs(int n) {
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};