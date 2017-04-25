/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

string reverseWords(string s) {
    int low = 0, high;
    while (low < s.size()) {
        high = s.find_first_of(' ', low);
        if (high == std::string::npos) {
            high = s.size();
        }
        std::reverse(s.begin()+low, s.begin()+high);
        low = high+1;
    }
    return s;
}
