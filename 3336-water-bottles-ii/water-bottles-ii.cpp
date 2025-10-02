class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int currBottles = numBottles;
        int currExchange = numExchange;

        while(currBottles>=currExchange){
            ans++;
            currBottles = currBottles - currExchange + 1;
            currExchange++;
        }

        return ans;

    }
};