class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int i = 0; i<stones.size();i++){
            q.push(stones[i]);
        }
        while(!q.empty()){
            int topStone = q.top();
            q.pop();
            if(q.empty()){
                return topStone;
            }
            int secondTopStone = q.top();
            q.pop();
            int diff = topStone-secondTopStone;
            q.push(diff);
        }
        return 0;
    }
};