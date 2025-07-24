class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);

        for(int i = 0; i<dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // 1->2,3
        // 2->1,3
        // 3->1,2
        vector<int>groups(n+1,-1);

        for(int i=1; i<=n; i++){
            if (groups[i] == -1) {
                queue<int>q;
                q.push(i);
                groups[i] = 1;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(auto j: adj[front]){
                    if(groups[j]==-1)q.push(j);
                    if(groups[front] == 1){
                        if(groups[j] == 1) return false;
                        groups[j] = 0;
                    }else if(groups[front] == 0){
                        if(groups[j] == 0) return false;
                        groups[j] = 1;
                    }
                }
            }


        }
        }
        return true;
    }
};