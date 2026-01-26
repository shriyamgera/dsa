class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto i:mp){
            if(i.second == 1) return -1;
            int val = i.second/3;
            if(i.second%3 == 0) ans+=val;
            else ans+=val+1;
        }
        return ans;
    }
};