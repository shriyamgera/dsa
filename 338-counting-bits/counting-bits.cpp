class Solution {
public:
    int solve(int n){
        int count = 0;
        for(int i=0; i<=17; i++){
            int last = n & 1;
            count+=last;
            n>>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};