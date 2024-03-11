class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for (int i=0;i<n;i++){
            if (nums[n-1] != n) return n;
            else if(nums[i]!=i){
                return i;
            }
        }
        return -1;
    }
};

// [0,1] [0,1,2]