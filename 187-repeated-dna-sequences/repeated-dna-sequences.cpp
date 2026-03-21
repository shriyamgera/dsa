class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        unordered_set<string>st;
        unordered_set<string>st2;
        for(int i=0; i<=s.size()-10; i++){
            string str = s.substr(i,10);
            if(st.find(str) != st.end()){
                st2.insert(str);
            }else{
                st.insert(str);
            }
        }
        vector<string>ans;
        for(auto &i:st2){
            ans.push_back(i);
        }
        return ans;
    }
};