/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

std::string countAndSay(int n)
{
    std::string num("1");
    while (--n > 0)
    {
        std::string dummy;
        int count = 1;
        for (int i = 0, iEnd = num.size(); i < iEnd; )
        {
            int j = i + 1;
            for (int jEnd = iEnd; j < jEnd; ++j)
            {
                if (num[j] != num[i]) break;
                count++;
            }

            dummy += std::to_string(count) + num[i];

            i = j;
            count = 1;
        }
        num = dummy;
    }
    return num;
}
