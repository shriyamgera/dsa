class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>>q;
        q.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        int steps = 0;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                vector<int> front = q.front();
                q.pop();
                int x = front[0];
                int y = front[1];

                if((front!=entrance) &&  (x == 0 || x == m-1 || y == 0 || y == n-1)){
                    return steps;
                }
                for(auto i: dirs){
                    int nx = front[0]+i[0];
                    int ny = front[1]+i[1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && maze[nx][ny] != '+'){
                        maze[nx][ny] = '+';
                        q.push({nx,ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};