// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
// design an algorithm to find the maximum profit.

int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
        
    int maxProfit = 0, minPrice = prices[0];
    for (int i = 1, iEnd = prices.size(); i < iEnd; ++i) {
        if (prices[i] > minPrice)
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
        else
            minPrice = std::min(prices[i], minPrice);
    }
    return maxProfit;
}
