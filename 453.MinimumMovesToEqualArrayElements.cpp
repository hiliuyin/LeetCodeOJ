/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:
Input:
[1,2,3]
Output:
3
Explanation:
Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

int minMoves(vector<int>& nums) {
    int min = INT_MAX, sum = 0;
    for (const auto& num : nums) {
        sum += num;
        min = std::min(min, num);
    }
    return sum - min * nums.size();
}
