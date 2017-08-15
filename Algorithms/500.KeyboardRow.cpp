/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
American keyboard

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

vector<string> findWords(vector<string>& words) {
    std::unordered_map<char, int> m;
    std::string s1("qwertyuiop"),  s2("asdfghjkl"), s3("zxcvbnm");
    for (const auto& ch : s1) {
        m[ch] = 1;
        m['A'+ ch-'a'] = 1;
    }
    for (const auto& ch : s2) {
        m[ch] = 2;
        m['A'+ ch-'a'] = 2;
    }
    for (const auto& ch : s3) {
        m[ch] = 3;
        m['A'+ ch-'a'] = 3;
    }
        
    std::vector<string> result;
    for (const auto& word : words) {
        bool oneRow = true;
        int row = m[word[0]];
        for (int i = 1, iEnd = word.size(); i < iEnd; ++i) {
            if (m[word[i]] != row) {
                oneRow = false;
                break;
            }
        }
        
        if (oneRow) {
            result.emplace_back(word);
        }
    }    
    return result;
}
