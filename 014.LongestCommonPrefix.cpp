/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    
    std::sort(strs.begin(), strs.end(), [](std::string &a, std::string &b) { return a.size() < b.size(); });
    
    std::string common = strs[0];
    for (auto&& str : strs) {
        int i = 0;
        for (int iEnd = (int)common.size(); i < iEnd; ++i) {
            if (common[i] != str[i])
                break;
        }
        common.erase(i);
    }
    
    return common;
}

// a more elegant solution : use lambda expression
std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) return {};

    auto helper = [](const std::string& s1, const std::string& s2) {
        int i = 0;
        for (int iEnd = s1.size(); i < iEnd; ++i) {
            if (s1[i] != s2[i]) break;
        }
        return i-1;
    };
    
    std::sort(strs.begin(), strs.end(),
        [](const std::string& a, const std::string& b){ return a.size() < b.size(); });
    
    auto prefix = strs.front();
    for (int i = 1, iEnd = strs.size(); i < iEnd; ++i) {
        auto index = helper(prefix, strs[i]);
        if (index == -1) return {};
        prefix.erase(index+1);
    }
    return prefix;
}
