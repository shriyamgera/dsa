class Solution {

private:
    void findPermutation(vector<int>& nums,int currIndex,vector<vector<int>>&ans){
    if(currIndex==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=currIndex;i<nums.size();i++){
        swap(nums[i],nums[currIndex]);
        findPermutation(nums,currIndex+1,ans);
        swap(nums[i],nums[currIndex]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int currIndex=0;
        findPermutation(nums,currIndex,ans);
        return ans;
    }
};



// class Solution {

// private:
//     void findPermutation(vector<int>&ds,vector<bool>&freq,vector<int>& nums,vector<vector<int>>&ans){
//         if(ds.size()==nums.size()){
//             ans.push_back(ds);
//              ds.pop_back();
//             return;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(!freq[i]){
//                 freq[i]=true;
//                 ds.push_back(nums[i]);
//                 findPermutation(ds,freq,nums,ans);
               
//                 freq[i]=false;
//             }
//         }
//     }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>ds;
//         vector<bool>freq(nums.size());
//         findPermutation(ds,freq,nums,ans);
//         return ans;
//     }
// };