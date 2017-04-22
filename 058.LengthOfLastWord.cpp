/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

int lengthOfLastWord(std::string s) {
    if (s.empty()) return 0;
    
    auto rit = s.rbegin();
    while (rit != s.rend()) {
        if (*rit == ' ')
            ++rit;
        else
            break;
    }
    
    if (rit == s.rend()) return 0;
    
    int len = 0;
    while (rit != s.rend()) {
        if (*rit == ' ') break;
        ++len;
        ++rit;
    }
    return len;
}

// use std::string APIs
int lengthOfLastWord(std::string s) {
    auto tail = s.find_last_not_of(' ');
    if (tail == std::string::npos) return 0;
    
    auto head = s.find_last_of(' ', tail);
    return head == std::string::npos ? tail+1 : tail-head;
}
