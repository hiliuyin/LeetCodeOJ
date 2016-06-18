/*
Given an array of n integers where n > 1, nums, 
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? 
(Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    std::vector<int> products;
    int val = 1;
    for (auto it = nums.cbegin(); it != nums.cend(); ++it)
    {
        val *= *it;
        products.emplace_back(val);
    }
    
    int temp = 1;
    for (int i = (int)nums.size()-1; i > 0; --i)
    {
        products[i] = products[i-1]*temp;
        temp *= nums[i];
    }
    products[0] = temp;
    
    return products;
}
