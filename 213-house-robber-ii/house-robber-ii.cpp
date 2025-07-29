class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int m = nums.size()-1;
        if(n==1) return nums[0];

        int a = 0;
        int b = nums[0];

        for(int i=1;i<m;i++){
            int c = b;
            int d = a + nums[i];
            a = b;
            b = max(c,d);
        }
        int rob1 = b;
        a = 0;
        b = nums[1];
        for(int i=2;i<n;i++){
            int c = b;
            int d = a + nums[i];
            a = b;
            b = max(c,d);
        }
        int rob2 = b;
        return max(rob1, rob2);
    }
};