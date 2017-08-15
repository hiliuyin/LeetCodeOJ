/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:
Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

int longestPalindrome(string s) {
    std::vector<int> v(52, 0);
    for (const auto& ch : s) {
        if (std::isupper(ch))
            v[ch-'A']++;
        else
            v[ch-'a'+26]++;
    }
    
    int result = 0;
    int oddNum = 0;
    for (const auto& x : v) {
        if (x % 2 == 0)
            result += x;
        else {
            result += x-1;
            oddNum++;
        }
    }
    
    return oddNum != 0 ? result+1 : result;
    
}
