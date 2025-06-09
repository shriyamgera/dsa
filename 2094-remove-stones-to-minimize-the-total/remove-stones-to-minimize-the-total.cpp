#include <queue>
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        for(int i=0;i<k;i++){
            int stonesToRemove = pq.top()/2;
            int stonesToPush = pq.top() - stonesToRemove;
            pq.pop();
            pq.push(stonesToPush);
        }
        int finalSum = 0;
        while(!pq.empty()){
            finalSum += pq.top();
            pq.pop();
        }
        return finalSum;
    }
};