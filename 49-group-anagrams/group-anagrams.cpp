class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>> ans;
        for(int i = 0; i<strs.size();i++){
            string sortedItem = strs[i];
            sort(sortedItem.begin(), sortedItem.end());
            mp[sortedItem].push_back(strs[i]);
        }
        for(auto [sorted, group]:mp){
            ans.push_back(mp[sorted]);
        }
        return ans;
    }
};