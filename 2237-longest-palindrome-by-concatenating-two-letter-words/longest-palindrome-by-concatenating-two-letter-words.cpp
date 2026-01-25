class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }
        bool usedOne = false;
        int ans = 0;
        for (string i : words) {
            string word = i;
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word != rev && mp[word] > 0 && mp[rev] > 0) {
                mp[word]--;
                mp[rev]--;
                ans += 4;
            } else if (word == rev && mp[word] >= 2) {
                mp[word] -= 2;
                ans += 4;
            } else if (word == rev && mp[word] == 1 && !usedOne) {
                usedOne = true;
                ans += 2;
            }
        }
        return ans;
    }
};