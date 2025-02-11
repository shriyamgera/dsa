class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);

        int lMax = 0;
        for(int i=0;i<n;i++){
            left[i] = max(lMax,height[i]);
            lMax = left[i];
        }

        int rMax = 0;
        for(int i=n-1;i>=0;i--){
            right[i] = max(rMax,height[i]);
            rMax = right[i];
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }

        return ans;
    }
};