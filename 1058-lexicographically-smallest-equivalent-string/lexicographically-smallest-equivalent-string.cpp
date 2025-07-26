class Solution {
public:

    char dfs(char curr,unordered_map<char,vector<char>>&adj,unordered_map<char,bool>&visited){
        visited[curr] = true;
        char minEl = curr;
        for(auto i: adj[curr]){
            if(!visited[i]){
                char el = dfs(i,adj,visited);
                minEl = min(minEl,el);
            }
        }
        return minEl;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>>adj;
        for(int i = 0;i<s1.size();i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        for(int i=0;i<baseStr.size();i++){
            char curr = baseStr[i];
            unordered_map<char,bool>visited(s1.size());
            char el = dfs(curr,adj,visited);
            ans += el;
        }
        return ans;
    }
};