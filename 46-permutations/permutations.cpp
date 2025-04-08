class Solution {

private:
    void findPermutation(vector<int>&ds,vector<bool>&freq,vector<int>& nums,vector<vector<int>>&ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=true;
                ds.push_back(nums[i]);
                findPermutation(ds,freq,nums,ans);
                ds.pop_back();
                freq[i]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<bool>freq(nums.size());
        findPermutation(ds,freq,nums,ans);
        return ans;
    }
};