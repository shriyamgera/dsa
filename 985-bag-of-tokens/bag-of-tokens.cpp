class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();

        int i = 0;
        int j = n-1;
        int ans = 0;

        int maxAns = 0;

        while(i<=j){
            if(tokens[i]<=power){
                power = power - tokens[i];
                ans++;
                i++;
                maxAns = max(maxAns,ans);
            }else if(ans>=1){
                power = power + tokens[j];
                ans--;
                j--;
          }else{
            return maxAns;
          }
        }

        return maxAns;
    }
};