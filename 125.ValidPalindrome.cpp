/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

bool isPalindrome(std::string s)
{
    for (int i = 0, j = s.size() - 1; i < j;)
    {
        while (i < (int)s.size() && !isalnum(s[i]))
            i++;
        while (j >= 0 && !isalnum(s[j]))
            j--;

        if (i >= j)
            break;

        if (toupper(s[i++]) == toupper(s[j--]))
            continue;
        else
            return false;
    }
    return true;
}
