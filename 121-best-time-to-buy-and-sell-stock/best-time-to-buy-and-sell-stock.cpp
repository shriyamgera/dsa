class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int currentProfit = 0;
        int maxProfit = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<buyPrice){
                buyPrice = prices[i];
                currentProfit = 0;
            }else{
                currentProfit = prices[i]-buyPrice;
                maxProfit = max(maxProfit, currentProfit);
            }
        }

        return maxProfit;
    }
};