/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

bool wordPattern(std::string pattern, std::string str) {
    std::vector<std::string> words;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        words.emplace_back(token);
    }
    
    if (pattern.size() != words.size()) return false;
    
    std::unordered_map<char, std::string> m1;
    std::unordered_map<std::string, char> m2;
    for (int i = 0, iEnd = pattern.size(); i < iEnd; ++i) {
        if (m1.find(pattern[i]) == m1.end()) {
            m1[pattern[i]] = words[i];
        }
        if (m2.find(words[i]) == m2.end()) {
            m2[words[i]] = pattern[i];
        }
        
        if (m1[pattern[i]] != words[i] || m2[words[i]] != pattern[i])
            return false;
    }
    return true;
}
