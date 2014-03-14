// Jump Game II 
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// 
// Each element in the array represents your maximum jump length at that position.
// 
// Your goal is to reach the last index in the minimum number of jumps.
// 
// For example:
// Given array A = [2,3,1,1,4]
// 
// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//

// Greedy Algorithm
// Calculate the furthest index in every jump
//
int jump(int A[], int n)
{
    if (n <= 0) return 0;
    if (A[0] == 0) return 0;
    if (n == 1 && A[0] > 0) return 0;

    int lastSofar = A[0];
    int jumps = 1;
    for (;;)
    {
        if (lastSofar >= (n-1))
            return jumps;
        
        jumps++;

        int k = lastSofar;
        for (int i = 1; i <= lastSofar; ++i)
        {
            k = std::max(A[i]+i, k);
        }
        // cannot move forward, just return 0 
        if (k == lastSofar) return 0;

        lastSofar = k;
    }
    
    return jumps;
}
