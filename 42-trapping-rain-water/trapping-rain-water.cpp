class Solution {
public:
    int trap(vector<int>& height) {
        // left and right no hold
        // array1
        // array2
        // height[4] = 1;
        // array1[4] = 2;
        // array2[4] = 3;

        int n = height.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);

        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            int maxPossibleHeight = min(leftMax[i], rightMax[i]);
            ans += maxPossibleHeight - height[i];
        }

        return ans;


    }
};