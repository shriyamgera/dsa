class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int steal = nums[i] + solve(nums,i+2,dp);
        int skip = solve(nums,i+1,dp);
        dp[i] = max(steal,skip);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};