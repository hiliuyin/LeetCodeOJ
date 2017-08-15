/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True

Example 2:
Input: "PPALLL"
Output: False
*/

// solution 1:
bool checkRecord(string s) {
    int absent = 0;
    char prevL = -1;
    for (int i = 0, iEnd = s.size(); i < iEnd; ++i) {
        if (s[i] == 'A') absent++;
        if (absent >= 2) return false;
        if (s[i] == 'L') {
            if (prevL == -1) prevL = i;
            if (i - prevL >= 2) return false;
        }
        else {
            prevL = -1;
        }
    }
    return true;
}

// solution 2: elegant code
bool checkRecord(string s) {
    int absent = 0, late = 0;
    for (const auto& ch : s) {
        if (ch == 'A') absent++;
        if (ch == 'L') late++;
        else late = 0;
        if (absent >= 2 || late > 2) return false;
    }
    return true;
}
