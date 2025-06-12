#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            int curr = nums[i];
            int more = target - curr;
            if(m.find(more) !=m.end()){
                ans.push_back(i);
                ans.push_back(m[more]);
                return ans;
            }else{
                m[curr] = i;
            }
        }
        return {};
    }
};