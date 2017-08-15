/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"

Example 2:
Input: -7
Output: "-10"

Note: The input will be in range of [-1e7, 1e7].
*/

string convertToBase7(int num) {
    std::string result;
    int x = std::abs(num);
    do {
        result = std::to_string(x % 7) + result;
    } while (x /= 7);
    return num < 0 ? "-" + result : result;
}
