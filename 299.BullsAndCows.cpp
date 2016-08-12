/*
You are playing the following Bulls and Cows game with your friend: 
You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates 
how many digits in said guess match your secret number exactly in both digit and position (called "bulls") 
and how many digits match the secret number but locate in the wrong position (called "cows"). 
Your friend will use successive guesses and hints to eventually derive the secret number.

For example:
Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, 
use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:
Secret number:  "1123"
Friend's guess: "0111"

In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/

std::string getHint(std::string secret, std::string guess)
{
    std::unordered_multimap<char, int> M;
    int bulls = 0;
    int cows = 0;
    
    for (int i = 0, iEnd = (int)secret.size(); i < iEnd; ++i)
    {
        M.emplace(secret[i], i);
    }
    
    std::string guessDummy;
    for (int i = 0, iEnd = (int)guess.size(); i < iEnd; ++i)
    {
        guessDummy.append(1, guess[i]);

        auto range = M.equal_range(guess[i]);
        for (auto it = range.first; it != range.second; ++it)
        {
            if (it->second == i)
            {
                bulls++;
                M.erase(it);
                guessDummy.erase(guessDummy.size() - 1);
                break;
            }
        }
    }
    
    for (int i = 0, iEnd = (int)guessDummy.size(); i < iEnd; ++i)
    {
        auto range = M.equal_range(guessDummy[i]);
        auto it = range.first;
        if (it != range.second)
        {
            M.erase(it);
            cows++;
        }
    }
    
    return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
}
