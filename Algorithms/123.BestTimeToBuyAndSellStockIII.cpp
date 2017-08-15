/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

// DP: 
int maxProfit(std::vector<int>& prices)
{
    if (prices.size() <= 1) return 0;
    
    std::vector<int> profits(prices.size(), 0);
    for (int i = 1, iEnd = (int)prices.size(), lowestPrice = prices[0]; i < iEnd; ++i)
    {
        if (prices[i] < lowestPrice)
            lowestPrice = prices[i];
        profits[i] = std::max(profits[i-1], prices[i] - lowestPrice);
    }
    
    int maxProfit = profits.back();
    for (int i = (int)prices.size()-1, highestPrice = 0; i > 0; --i)
    {
        highestPrice = std::max(prices[i], highestPrice);
        maxProfit = std::max(maxProfit, (highestPrice - prices[i])+profits[i-1]);
    }
    return maxProfit;
}

// Another solution: time limit exceeded
int maxProfit(std::vector<int>& prices)
{
    if (prices.size() <= 1) return 0;
    
    auto calcMaxProfit = [&](int from, int to) -> int
    {
        if (to == from) return 0;
        int maxEndinghere = 0, maxSofar = 0, price = prices[from];
        for (int i = from+1; i <= to; ++i)
        {
            if (prices[i] > price)
                maxEndinghere = prices[i] - price;
            else
                price = prices[i];
            
            maxSofar = std::max(maxSofar, maxEndinghere);
        }
        return maxSofar;
    };
    
    int maxProfit = 0;
    for (int i = 0, iEnd = (int)prices.size(); i < iEnd; ++i)
    {
        maxProfit = std::max(maxProfit, calcMaxProfit(0, i)+calcMaxProfit(i+1, iEnd-1));
    }
    return maxProfit;
}
