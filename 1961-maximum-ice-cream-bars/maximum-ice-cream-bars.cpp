class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        int currentCost = 0;
        for(int i=0; i<costs.size();i++){
            currentCost += costs[i];
            if(currentCost<=coins) count++;
            else break;
        }
        return count;
    }
};