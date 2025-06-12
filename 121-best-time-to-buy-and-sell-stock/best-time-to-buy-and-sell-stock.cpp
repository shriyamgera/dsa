class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //     int ans = 0;
    //     for(int i=0; i<prices.size();i++){
    //         for(int j=i+1;j<prices.size();j++){
    //             ans = max(ans, prices[j] - prices[i]);
    //         }
    //     }
    //     return ans;
    // }
    int minimal = prices[0];
    int profit = 0;
    for(int i=1;i<prices.size();i++){
        minimal = min(minimal,prices[i]);
        profit = max( profit, prices[i] - minimal);
    }
    return profit;
    }
};