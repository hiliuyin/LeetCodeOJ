/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.

Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
*/

// binary search, O(nlgn) + O(mlgn)
int findRadius(vector<int>& houses, vector<int>& heaters) {
    std::sort(heaters.begin(), heaters.end());
    
    auto binarySearch = [&heaters](int val) {
        int low = 0, high = heaters.size() - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (heaters[mid] == val) {
                return mid;
            }
            else if (heaters[mid] > val) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    };
    
    int res = INT_MIN;
    for (const auto& house : houses) {
        auto pos = binarySearch(house);
        if (pos == heaters.size()) {
            res = std::max(res, std::abs(house - heaters[pos-1]));
        }
        else if (pos == 0 ) {
            res = std::max(res, std::abs(house - heaters[pos]));
        }
        else if (heaters[pos] == house) {
            res = std::max(res, 0);
        }
        else {
            res = std::max(res, std::min(std::abs(house - heaters[pos-1]), std::abs(house - heaters[pos])));
        }
    }
    return res;
}

