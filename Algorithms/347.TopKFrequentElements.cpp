/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

// Solution 1: using std::priority_queue
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> m;
    for (const auto& num : nums) {
        m[num]++;
    }
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for (auto it = m.begin(); it != m.end(); ++it) {
        pq.emplace(it->second, it->first);
        if (pq.size() > k) pq.pop();
    }
    
    std::vector<int> result;
    while (!pq.empty()) {
        result.emplace_back(pq.top().second);
        pq.pop();
    }
    return result;
}

// Solution 2: using std::make_heap
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> m;
    for (const auto& num : nums) {
        m[num]++;
    }
    
    std::vector<std::pair<int, int>> vec;
    for (auto it = m.begin(); it != m.end(); ++it) {
        vec.emplace_back(it->second, it->first);
    }
    
    std::make_heap(vec.begin(), vec.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.first < b.first; });
    
    std::vector<int> result;
    while (k-- > 0) {
        std::pop_heap(vec.begin(), vec.end());
        result.emplace_back(vec.back().second);
        vec.pop_back();
    }
    return result;
}
