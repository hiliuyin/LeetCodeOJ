/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

string countAndSay(int n) {
    if (n <= 0) return {};

    std::string result{"1"};
    for (int i = 1; i < n; ++i) {
        std::string str;
        char prev = result[0];
        int count = 1;
        for (int k = 1, kEnd = result.size(); k < kEnd; ++k) {
            if (result[k] == prev) {
                ++count;
            }
            else {
                str += std::to_string(count) + prev;
                prev = result[k];
                count = 1;
            }
        }
        str += std::to_string(count) + prev;
        result = str;
    }
    return result;
}
