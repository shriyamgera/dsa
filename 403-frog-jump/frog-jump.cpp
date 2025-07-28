class Solution {
public:
    unordered_map<int,unordered_map<int, bool>>dp;
    bool solve(unordered_map<int,int>&mp, int last, int curr, int step){
        if(curr == last){
            return true;
        }
        if(dp.count(curr) && dp[curr].count(step)) return dp[curr][step];;
        if(mp.find(curr)==mp.end()){
            return false;
        }
        vector<int>next = {-1,0,1};
        
        bool ans = false;
        for(auto i: next){
            if (step+i<=0) continue;
            int nextStep = step + i;
            int nextCurr = curr+step;
            ans = ans || solve(mp,last,nextCurr,nextStep);
            if(ans){
                dp[curr][step] = true;
            }else{
                dp[curr][step] = false;
            }
        }
        return ans;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        int last = stones[stones.size()-1];
        return solve(mp,last,0,0);
    }
};