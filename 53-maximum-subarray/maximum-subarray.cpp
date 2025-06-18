class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int currSubSum = 0;
    //     int maxSum = nums[0];
    //     for(int i = 0; i<nums.size();i++){
    //         currSubSum += nums[i];
    //         maxSum = max(currSubSum, maxSum);
    //         if(currSubSum<0) currSubSum = 0;
    //     }
    //     return maxSum;
    // }
    int maxSubArray(vector<int>& nums) {
        int currSubSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i<nums.size();i++){
            currSubSum = max(nums[i], currSubSum + nums[i]);
            maxSum = max(currSubSum, maxSum);
        }
        return maxSum;
    }
};