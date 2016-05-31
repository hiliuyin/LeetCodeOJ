

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::size_type sz = nums.size();
        if (sz == 0) return -1;
        
        int insertIndex = -1;
        int begin = 0, end = (int)sz-1;
        do
        {
            int mid = (begin + end)/2;
            if (nums[mid] > target)
            {
                insertIndex = mid;
                end = mid-1;
            }
            else if (nums[mid] < target)
            {
                insertIndex = mid+1;
                begin = mid+1;
            }
            else // nums[mid] == target
            {
                insertIndex = mid;
                break;
            }
        } while (begin <= end);

        return insertIndex;
    }
};
