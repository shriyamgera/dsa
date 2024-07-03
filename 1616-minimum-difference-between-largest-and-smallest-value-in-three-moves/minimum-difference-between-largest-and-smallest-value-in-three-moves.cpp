class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        if(n<=4){
            return 0;
        }

        int ans,a1,a2,a3,a4;

        a1=nums[n-1]-nums[3];
        a2=nums[n-4]-nums[0];
        a3=nums[n-2]-nums[2];
        a4=nums[n-3]-nums[1];

        ans=min({a1,a2,a3,a4});

        return ans;

    }
};