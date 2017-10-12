/*
Suppose Andy and Doris want to choose a restaurant for dinner,
and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum.
If there is a choice tie between answers, output all of them with no order requirement.
You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".

Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    std::unordered_map<string, int> um1, um2;
    for (int i = 0, iEnd = list1.size(); i < iEnd; ++i) {
        um1[list1[i]] = i;
    }
    for (int j = 0, jEnd = list2.size(); j < jEnd; ++j) {
        um2[list2[j]] = j;
    }
    
    std::vector<string> result;
    int sum = INT_MAX;
    for (const auto& n : um1) {
        if (um2.find(n.first) != um2.end()) {
            if (n.second + um2[n.first] < sum) {
                result.clear();
                result.emplace_back(n.first);
                sum = n.second + um2[n.first];
            } else if (n.second + um2[n.first] == sum) {
                result.emplace_back(n.first);
            }
        }
    }
    return result;
}
