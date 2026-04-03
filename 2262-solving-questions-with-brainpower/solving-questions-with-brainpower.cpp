class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(200001, 0);
        int n = questions.size();
        for(int i = n-1; i>=0; i--){
            dp[i] = max((questions[i][0]+dp[i+questions[i][1]+1]),dp[i+1]);
        }
        return dp[0];
    }
};