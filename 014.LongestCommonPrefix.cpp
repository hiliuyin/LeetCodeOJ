/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    if (strs.empty()) return "";
    
    std::sort(strs.begin(), strs.end(), [](std::string &a, std::string &b) { return a.size() < b.size(); });
    
    std::string common = strs[0];
    for (auto&& str : strs)
    {
        int i = 0;
        for (int iEnd = (int)common.size(); i < iEnd; ++i)
        {
            if (common[i] != str[i])
                break;
        }
        common.erase(i);
    }
    
    return common;
}

