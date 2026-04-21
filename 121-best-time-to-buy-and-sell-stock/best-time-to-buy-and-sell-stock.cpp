class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = 0 , profit = 0;
        int minElement = prices[0];

        for(int i = 0; i<n ; i++){
            cost = prices[i] - minElement;
            profit = max(cost , profit);
            minElement = min(prices[i], minElement);
        }
        
        return profit;
    }
};