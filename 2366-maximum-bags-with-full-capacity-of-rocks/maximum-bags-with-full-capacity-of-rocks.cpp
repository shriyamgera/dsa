class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>diff;
        for(int i=0;i<rocks.size();i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(), diff.end());
        int count = 0;
        for(int i=0; i<rocks.size();i++){
            if(diff[i] == 0) count++;
            if(diff[i] != 0){
                additionalRocks = additionalRocks - diff[i];
                if(additionalRocks>=0) count++;
                else break;
            }
        }
        return count;
    }
};