class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftCommSum(n);
        vector<int>rightCommSum(n);
        int prev = 1;
        int next = 1;
        for(int i=0; i<n; i++){
            leftCommSum[i] = prev*nums[i];
            prev = leftCommSum[i];
        }
        for(int i=n-1; i>=0; i--){
            rightCommSum[i] = next*nums[i];
            next = rightCommSum[i];
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int left = (i==0) ? 1 : leftCommSum[i-1];
            int right = (i==n-1) ? 1 : rightCommSum[i+1];
            ans[i] = left*right;
        }
        return ans;
    }
};