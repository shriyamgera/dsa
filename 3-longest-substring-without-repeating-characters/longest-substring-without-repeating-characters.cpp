#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int maxCount = 0;
        for(int i = 0;i<s.length();i++){
            int count = 0;
            vector<bool>mpp(256,0);
            for(int j = i; j<s.length();j++){
                if(mpp[s[j]]) {
                    break;
                };
                mpp[s[j]] = true;
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};