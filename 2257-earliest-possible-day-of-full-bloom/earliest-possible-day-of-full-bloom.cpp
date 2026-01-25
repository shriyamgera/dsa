class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>p;
        int n = growTime.size();
        for(int i=0; i<n; i++){
            p.push_back({growTime[i],plantTime[i]});
        }
        sort(p.rbegin(),p.rend());

        int maxBloomDays = 0;
        int prevPlantDays = 0;
        for(int i=0; i<n; i++){
            int pTime = p[i].second;
            int gTime = p[i].first;
            prevPlantDays += pTime;
            int currBloomDays = prevPlantDays+gTime;
            maxBloomDays =max(maxBloomDays,currBloomDays);

        }

        return maxBloomDays;
    }
};