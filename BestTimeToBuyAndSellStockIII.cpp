// Best Time to Buy and Sell Stock III
// Say you have an array for which the ith element is the price of a given stock on day i.
// 
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
// 
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Dynamic Programming
//
int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0) return 0;
    
    int maxprofitSofar = 0;
    
    // forward loop the prices the 1st part
    int lowestPriceSofar = prices[0];
    std::vector<int> profit1st;
    profit1st.assign(prices.size(), 0);
    for (int i = 1; i < prices.size(); ++i)
    {
        lowestPriceSofar = std::min(lowestPriceSofar, prices[i]);
        profit1st[i] = std::max(profit1st[i-1], prices[i]-lowestPriceSofar);
    }
    
    // backward loop the prices for the second part
    int highestPriceSofar = prices[prices.size()-1];
    std::vector<int> profit2nd;
    profit2nd.assign(prices.size(), 0);
    for (int j = (int)prices.size()-1; j >= 1; --j)
    {
        highestPriceSofar = std::max(highestPriceSofar, prices[j]);
        
        if (j < (int)prices.size()-1)
            profit2nd[j] = std::max(profit2nd[j+1], highestPriceSofar-prices[j]);

        maxprofitSofar = std::max(maxprofitSofar, profit1st[j]+profit2nd[j]);
    }
    
    return maxprofitSofar;
}
