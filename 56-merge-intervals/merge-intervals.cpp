class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int j = 1;
        int i = 0;
        for(;i<intervals.size();i=j){
            for(j=i+1;j<intervals.size();j++){
                if(intervals[i][1]>=intervals[j][0]){
                    intervals[i][1]=max(intervals[j][1],intervals[i][1]);
                }else {
                    break;
                }
            }
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};