class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxPriceInFuture(prices.size(), 0);

        int futureMaxPrice=prices[prices.size()-1];
        maxPriceInFuture[prices.size()-1] = prices[prices.size()-1];

        for(int i=prices.size()-2; i>=0; i--){
            maxPriceInFuture[i] = futureMaxPrice;
            futureMaxPrice = max(futureMaxPrice, prices[i]);
        }

        int maxProfit = 0;
        for(int i=0;i<prices.size(); i++){
            int maxProfitForCurDay = maxPriceInFuture[i]-prices[i];
            maxProfit = max(maxProfit, maxProfitForCurDay);
        }

        return maxProfit;
    }
};
