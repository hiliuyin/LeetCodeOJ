// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
// design an algorithm to find the maximum profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>::size_type sz = prices.size();
        if (sz <= 1) return 0;

        int minPriceEndingHere = prices[0], maxProfitSofar = 0;
        for (vector<int>::size_type i = 1; i < sz; ++i)
        {
            int price = prices[i];
            if (price > minPriceEndingHere)
            {
                maxProfitSofar = std::max(maxProfitSofar, price-minPriceEndingHere);
            }
            else
            {
                minPriceEndingHere = price;
            }
        }
        return maxProfitSofar;
    }
};
