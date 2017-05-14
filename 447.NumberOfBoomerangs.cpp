/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]
Output:
2
Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

int numberOfBoomerangs(vector<pair<int, int>>& points) {
    const int sz = points.size();
    int res = 0;
    for (int i = 0; i < sz; ++i) {
        std::unordered_map<int, int> group(sz);
        for (int j = 0; j < sz; ++j) {
            if (i == j) continue;
            
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            int dist = dx * dx + dy * dy;
            group[dist]++;
        }
        
        for (const auto& p : group) {
            if (p.second > 1) {
                res += p.second * (p.second - 1);
            }
        }
    }
    return res;
}
