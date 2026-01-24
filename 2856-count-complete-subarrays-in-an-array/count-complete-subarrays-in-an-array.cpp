class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>s;
        for(int i=0; i<nums.size();i++){
            s.insert(nums[i]);
        }
        int u = s.size();
        int n = nums.size();

        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==u){
                ans +=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};