class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int currVal = numBottles;
        int currRemainder = 0;

        while(currVal !=0){
            ans += currVal;
            currVal += currRemainder;
            currRemainder = currVal % numExchange;
            currVal = currVal / numExchange;
        }

        return ans;
    }
};