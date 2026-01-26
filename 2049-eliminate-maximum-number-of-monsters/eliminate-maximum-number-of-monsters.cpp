class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = speed.size();
        vector<int>time(n,0);
        for(int i=0; i<n; i++){
            double t = (double)dist[i]/speed[i];
            time[i] = ceil(t);
        }
        sort(time.begin(),time.end());
        int timeSpent = 1;
        int ans = 1;
        for(int i=1; i<n; i++){
            if(time[i]-timeSpent>0){
                ans++;
                timeSpent++;
            }
            else break;
        }
        return ans;

    }
};