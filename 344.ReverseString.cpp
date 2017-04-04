/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        int low = 0, high = static_cast<int>(s.size()) - 1;
        while (low < high) {
            std::swap(s[low++], s[high--]);
        }
        return s;
    }
};
