/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
Please note that the string does not contain any non-printable characters.

Example:
Input: "Hello, my name is John"
Output: 5
*/

int countSegments(string s) {
    if (s.empty()) return 0;
    int count = 0;
    int pos = -1;
    for (;;) {
        pos = s.find_first_not_of(' ', pos+1);
        if (pos == std::string::npos) break;
        ++count;
        pos = s.find_first_of(' ', pos+1);
        if (pos == std::string::npos) break;
    }
    return count;
}
