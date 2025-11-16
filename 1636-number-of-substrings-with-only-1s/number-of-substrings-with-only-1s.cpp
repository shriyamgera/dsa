class Solution {
public:
    int numSub(string s) {
        int c = 0;
        long long ans = 0;
        int mod = 1e9 + 7;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                c++;
            }else{
                ans += (1LL*c*(c+1)/2)%mod;
                c = 0;
            }
        }

        ans += (1LL*c*(c+1)/2)%mod;

        return ans;
    }
};