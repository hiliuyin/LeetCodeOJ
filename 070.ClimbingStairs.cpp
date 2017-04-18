// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Dynamic Programming: Fibonacci
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2) return n;
        int waysN, waysN_1 = 2, waysN_2 = 1;
        for (int i = 3; i <= n; ++i) {
            waysN = waysN_1 + waysN_2;
            waysN_2 = waysN_1;
            waysN_1 = waysN;
        }
        return waysN;
    }
};
