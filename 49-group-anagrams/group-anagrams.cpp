class Solution {
public:
    string encodeString(string str){
        vector<int> encodedArr(26,0);
        for(char c:str){
            encodedArr[c - 'a']++;
        }
        string encodedStr = "";
        for(int i=0; i<encodedArr.size();i++){
            if(encodedArr[i] !=0){
                encodedStr += char('a'+i) + to_string(encodedArr[i]);
            }
        }
        return encodedStr;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i = 0; i<strs.size(); i++){
            string encodedString = encodeString(strs[i]);
            mp[encodedString].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto [sorted, group]:mp){
            ans.push_back(mp[sorted]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string,vector<string>>mp;
//         vector<vector<string>> ans;
//         for(int i = 0; i<strs.size();i++){
//             string sortedItem = strs[i];
//             sort(sortedItem.begin(), sortedItem.end());
//             mp[sortedItem].push_back(strs[i]);
//         }
//         for(auto [sorted, group]:mp){
//             ans.push_back(mp[sorted]);
//         }
//         return ans;
//     }
// };