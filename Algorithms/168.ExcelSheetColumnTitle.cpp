/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

string convertToTitle(int n) {
    std::string result;
    while (n > 0) {
        result = static_cast<char>((n - 1)% 26 + 'A') + result;
        n = (n-1) / 26;
    }
    return result;
}
