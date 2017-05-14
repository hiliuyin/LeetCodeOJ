/*
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
*/

string intToRoman(int num) {
    std::unordered_map<int, string> M = {{0, ""}, {1, "M"}, {2, "MM"}, {3, "MMM"}};
    std::unordered_map<int, string> C = {{0, ""}, {1, "C"}, {2, "CC"}, {3, "CCC"}, {4, "CD"}, {5, "D"},
        {6, "DC"}, {7, "DCC"}, {8, "DCCC"}, {9, "CM"}};
    std::unordered_map<int, string> X = {{0, ""}, {1, "X"}, {2, "XX"}, {3, "XXX"}, {4, "XL"}, {5, "L"},
        {6, "LX"}, {7, "LXX"}, {8, "LXXX"}, {9, "XC"}};
    std::unordered_map<int, string> I = {{0, ""}, {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"},
        {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
