class Solution {
public:
    void backtrack(string s,vector<string>&ans,int dots, int cI, string cS){
        if(dots==4 && cI == s.length()){
            cS.pop_back();
            ans.push_back(cS);
            return;
        }
        if(dots>=4) return;
        for(int i=1; i<=3 && cI+i<=s.length();i++){
            string part = s.substr(cI,i);
            if((part[0] == '0' && part.length()>1) || stoi(part)>255) continue;
            backtrack(s,ans,dots+1,cI+i,cS+part+".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans={};
        if(s.length()>12 || s.length()<4) return ans;
        backtrack(s,ans,0,0,"");
        return ans;
    }
};