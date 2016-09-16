/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
// Solution 1: O(N) solution
int singleNumber(std::vector<int>& nums)
{
    std::map<int, int> m;
    for (auto it = nums.cbegin(); it != nums.cend(); ++it)
    {
        if (m.find(*it) != m.end())
            m[*it]++;
        else
            m[*it] = 1;
    }
    
    auto search = std::find_if(m.begin(), m.end(),
                               [&](const std::pair<int, int>& p)
                               { return p.second != 3; });
    return search->first;
}

// Solution 2: count the number of bits
int singleNumber(std::vector<int>& nums)
{
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; ++i)
    {
        for (auto&& num : nums)
        {
            if ((num>>i) & 1)
                count[i]++;
        }
        result |= (count[i]%3) << i;
    }
    return result;
}

// Solution 3: use bit manip
int singleNumber(std::vector<int>& nums)
{
    int ones = 0, twos = 0, threes = 0;
    for (auto&& num : nums)
    {
        twos |= ones & num;   // bit occurs twice
        ones ^= num;          // bit occurs once
        threes = ones & twos; // bit occurs three times
        
         // clear the bit which occurs three times
        ones &= ~threes;
        twos &= ~threes; 
    }
    return ones;
}
