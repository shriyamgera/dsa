class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int currVal = numBottles;
        int currRemainder = 0;

        while(true){
            currRemainder = currVal % numExchange;
            currVal = currVal / numExchange;
            ans += currVal;
            currVal += currRemainder;
            if(currVal / numExchange == 0) break;
        }

        return ans;
    }
};