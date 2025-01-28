class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        
        int sP = 0;
        int gP = 0;

        while(sP<s.size() && gP<g.size()){
            if(s[sP]>=g[gP]) gP++;
            sP++;

        }
        return gP;
    }
};