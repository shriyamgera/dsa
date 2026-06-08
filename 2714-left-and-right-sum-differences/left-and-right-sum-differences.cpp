class Solution {
public:
int sum(vector<int>&nums){
    int c = 0;
    for(int i=0; i<nums.size();i++){
        c +=nums[i];
    }
    return c;
}
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int l = 0;
        int r = sum(nums) - nums[0];
        for(int i=1;i<=n;i++){
            ans[i-1] = (abs(l-r));
            l += nums[i-1];
            if(i<n) r -= nums[i];
        }

        return ans;
    }
};