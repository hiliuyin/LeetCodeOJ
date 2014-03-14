// Anagrams 
// Given an array of strings, return all groups of strings that are anagrams.
// 
// Note: All inputs will be in lower-case.

// Use the sorted string as the key of the hash table
vector<string> anagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> strMap;
    vector<string> result;

    for (int i = 0; i < (int)strs.size(); ++i)
    {
        string strDummy{strs[i]};
        std::sort(strDummy.begin(), strDummy.end());
        
        strMap[strDummy].push_back(strs[i]);
    }
    
    for (unordered_map<string, vector<string>>::const_iterator it = strMap.begin();
         it != strMap.end();
         ++it)
    {
        if (it->second.size() > 1)
        {
            for (int i = 0; i < it->second.size(); ++i)
                result.push_back((it->second)[i]);
        }
    }
    
    return result;
}
