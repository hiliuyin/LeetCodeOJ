// ZigZag Conversion 
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// 
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// 
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

std::string convert(std::string s, int nRows)
{
    if (s.size() == 0 || nRows <= 0) return "";
    if (nRows == 1) return s;
    
    std::string zigzag;
    for (int i = 0; i < nRows; ++i)
    {
        int steps = 0;
        if (i == 0 || i == (nRows-1))
            steps = (nRows-1-i) + i + (nRows - 2);
        else
            steps = (nRows-1-i) + (i-1);
        
        for (int j = i; j < s.length(); j+=steps+1)
            zigzag.push_back(s[j]);
    }
    
    return zigzag;
}
