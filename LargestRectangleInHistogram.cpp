// Largest Rectangle in Histogram 
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
// 
// For example,
// Given height = [2,1,5,6,2,3],
// return 10.

//
// An divide & conquer method.
// Use the minimal height as the divider, recursively solve the subproblems.
// Worst case: T(n) = T(n-1)+O(n)  -> O(n^2)
// Normal case: T(n) = T(n/2)+O(n) -> O(nlgn)
//
int calculateArea(vector<int> &height, int start, int last)
{
    if (start > last) return 0;
    
    int valleyHeight = INT_MAX;
    int valleyIndex = -1;
    for (int i = start; i <= last; ++i)
    {
        if (height[i] <= valleyHeight)
        {
            valleyHeight = height[i];
            valleyIndex = i;
        }
    }

    int area1 = valleyHeight * (last-start+1);
    int area2 = calculateArea(height, start, valleyIndex-1);
    int area3 = calculateArea(height, valleyIndex+1, last);
    
    return std::max(std::max(area1, area2), area3);
}

int largestRectangleArea(vector<int> &height)
{
    return calculateArea(height, 0, (int)height.size()-1);
}

// TODO: try an O(n) way
