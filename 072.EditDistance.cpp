/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
int minDistance(std::string word1, std::string word2)
{
    if (word1.empty()) return (int)word2.size();
    if (word2.empty()) return (int)word1.size();
    
    std::vector<int> temp(word2.size()+1, 0);
    std::vector<std::vector<int>> dists(word1.size()+1, temp);
    
    if (word1[0] == word2[0])
        dists[1][1] = 0;
    for (int i = 1, iEnd = (int)word1.size()+1; i < iEnd; ++i)
        dists[i][0] = i;
    for (int i = 1, iEnd = (int)word2.size()+1; i < iEnd; ++i)
        dists[0][i] = i;

    for (int i = 0, iEnd = (int)word1.size(); i < iEnd; ++i)
    {
        for (int j = 0, jEnd = (int)word2.size(); j < jEnd; ++j)
        {
            if (word1[i] == word2[j])
                dists[i+1][j+1] = dists[i][j];
            else
            {
                int dist1 = dists[i][j] + 1; // replace
                int dist2 = dists[i][j+1] + 1;   // delete
                int dist3 = dists[i+1][j] + 1;   // insert
                
                dists[i+1][j+1] = std::min(dist1, std::min(dist2, dist3));
            }
        }
    }
    
    return dists[word1.size()][word2.size()];
}
};
