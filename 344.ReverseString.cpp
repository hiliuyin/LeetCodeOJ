/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        if (s.empty()) return s;
        
        const int sz = s.size();
        for (int low = 0, high = sz-1; low <= high; ++low, --high)
        {
            auto temp = s[low];
            s[low] = s[high];
            s[high] = temp;
        }
        return s;
    }
};
