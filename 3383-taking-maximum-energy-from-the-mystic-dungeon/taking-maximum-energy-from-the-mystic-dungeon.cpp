class Solution {
public:
    int solve(vector<int>& energy, int i, int k, vector<int>& dp) {
        if (i >= energy.size()) {
            return 0;
        }
        if (dp[i] != INT_MIN) {
            return dp[i];
        }
        return dp[i] = energy[i] + solve(energy, i + k, k, dp);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        vector<int> dp(energy.size(), INT_MIN);

        for (int i = 0; i < energy.size(); i++) {
            ans = max(ans, energy[i] + solve(energy, i+k, k, dp));
        }

        return ans;
    }
};