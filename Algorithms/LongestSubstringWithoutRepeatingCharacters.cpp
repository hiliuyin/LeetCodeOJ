// Longest Substring Without Repeating Characters 
// Given a string, find the length of the longest substring without repeating characters.
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
// For "bbbbb" the longest substring is "b", with the length of 1.

int lengthOfLongestSubstring(string s)
{
    if (s.length() <= 0) return 0;
    
    int lengthSofar = 0;
    int lengthEndinghere = 0;
    int lastIndex[256];
    bool appear[256];
    
    memset(lastIndex, 0, sizeof(lastIndex));
    memset(appear, 0, sizeof(appear));
    
    for (int i = 0; i < s.length(); ++i)
    {
        if (appear[s[i]])
        {
            lengthEndinghere = i - lastIndex[s[i]];
            
            for (int j = 0; j < 256; ++j)
            {
                if (j != s[i] && appear[j] && lastIndex[j] < lastIndex[s[i]])
                    appear[j] = false;
            }
        }
        else
        {
            appear[s[i]] = true;
            ++lengthEndinghere;
        }
        lastIndex[s[i]] = i;

        lengthSofar = std::max(lengthSofar, lengthEndinghere);
    }

    return lengthSofar;
}
