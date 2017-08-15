/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

bool isPalindrome(string s) {
    int low = 0, high = s.size()-1, sz = s.size();
    while (low < high) {
        while (low < sz && !std::isalnum(s[low])) ++low;
        if (low >= sz) break;
        while (high >= 0 && !std::isalnum(s[high])) --high;
        if (high < 0) break;
        
        if (low >= high) break;

        if (std::toupper(s[low++]) != std::toupper(s[high--])) return false;
    }
    return true;
}
