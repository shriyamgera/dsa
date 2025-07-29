    class Solution {
    public:
    vector<int>dp;
    int solve(vector<int>& nums, int i,int last){
        if(i>=last) return 0;

        if(dp[i]!=-1) return dp[i];
        
        int steal = nums[i] + solve(nums,i+2,last);
        int skip = solve(nums,i+1,last);

        dp[i] = max(steal,skip);
        return dp[i];
    }
        int rob(vector<int>& nums) {
            int n = nums.size();
            int m = nums.size()-1;
             if (n == 1) return nums[0];
            dp = vector<int>(n+1,-1);
            int rob1 = solve(nums,0,m);
            dp = vector<int>(n+1,-1);
            int rob2 = solve(nums,1,n);
            return max(rob1,rob2);
        }
    };