/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
*/

int compareVersion(std::string version1, std::string version2)
{
    for (std::size_t i = 0, j = 0;;)
    {
        std::size_t ii = version1.find('.', i);
        std::size_t jj = version2.find('.', j);
        
        unsigned long num1 = std::stoul(version1.substr(i, ii));
        unsigned long num2 = std::stoul(version2.substr(j, jj));
        
        if (num1 > num2) return 1;
        if (num1 < num2) return -1;
        
        if (ii == std::string::npos && jj == std::string::npos)
            break;
        if (ii == std::string::npos)
        {
            for (;;) // in case of 1.0.0.0........0.1
            {
                std:size_t jjj = version2.find('.', jj+1);
                if (std::stoul(version2.substr(jj+1, jjj)) > 0)
                    return -1;
                if (jjj == std::string::npos)
                    return 0;
                jj = jjj;
            }
        }
        if (jj == std::string::npos)
        {
            for (;;)  // in case of 1.0.0.0........0.1
            {
                std::size_t iii = version1.find('.', ii+1);
                if (std::stoul(version1.substr(ii+1, iii)) > 0)
                    return 1;
                if (iii == std::string::npos)
                    return 0;
                ii = iii;
            }
        }
        
        i = ii+1;
        j = jj+1;
    }
    
    return 0;
}
