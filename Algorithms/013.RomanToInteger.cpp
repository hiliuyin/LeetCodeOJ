/*
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

int romanToInt(string s) {
    std::unordered_map<char, int> um = 
        { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    
    int res = um[s.back()];
    for (int i = s.size() - 2; i >= 0; --i) {
        if (um[s[i]] < um[s[i+1]]) {
            res -= um[s[i]];
        }
        else {
            res += um[s[i]];
        }
    }
    return res;
}
