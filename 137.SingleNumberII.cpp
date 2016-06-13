/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

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

