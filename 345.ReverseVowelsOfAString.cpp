/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

std::string reverseVowels(std::string s)
{
    if (s.size() <= 1) return s;
    
    auto isVowel = [](char ch) -> bool {
        switch(ch) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
        default:
            return false;
        }
    };
    
    for (int i = 0, j = (int)s.size()-1; i < j; ++i, --j) {
        for (int iEnd = (int)s.size()-1; i < iEnd; ++i) {
            if (isVowel(s[i]))
                break;
        }
        
        for (int jEnd = 0; j >= jEnd; --j) {
            if (isVowel(s[j]))
                break;
        }
        
        if (i < j)
            std::swap(s[i], s[j]);
    }
    return s;
}

// solution 2: use std::string API
std::string reverseVowels(std::string s) {
    std::string::size_type low = s.find_first_of("aeiou", 0), high = s.find_last_of("aeiou", std::string::npos);
    while (low < high) {
        std::swap(s[low], s[high]);
        low = s.find_first_of("aeiou", low+1);
        high = s.find_last_of("aeiou", high-1);
    }
    return s;
}
