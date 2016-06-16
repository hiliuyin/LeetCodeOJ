/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
    if (strs.empty()) return {};

    std::unordered_map<std::string, std::vector<std::string>> m;
    for (int i = 0, iEnd = strs.size(); i < iEnd; ++i)
    {
        std::string strCopy(strs[i]);
        std::sort(strCopy.begin(), strCopy.end());

        m[strCopy].emplace_back(strs[i]);
    }

    std::vector<std::vector<std::string>> result;
    for (auto it = m.cbegin(); it != m.cend(); ++it)
    {
        result.emplace_back(it->second);
    }
    return result;
}
