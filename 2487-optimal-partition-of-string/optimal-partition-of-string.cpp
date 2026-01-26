class Solution {
public:
    int partitionString(string s) {
        vector<int>mp(26,-1);
        int currentStart = 0;
        int ans=1;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]-'a']>=currentStart){
                currentStart = i;
                ans++;
            }
            mp[s[i]-'a'] = i;
        }
        return ans;
    }
};