class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if(profit < prices[i]-buy)
                profit = prices[i]-buy;
            if(buy > prices[i])
                buy = prices[i];
        } 
        return profit;
    }
};