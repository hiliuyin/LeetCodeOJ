/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. 
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. 
Find how many bulbs are on after n rounds.

Example:
Given n = 3. 
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/

// 其实就看i的因子个数，对于普通的数来说，因子都是成对出现的
// 例如：8(1, 2, 4, 8), 10(1, 2, 5, 10)....
// 但是对于 完全平方数 来说，因子个数是奇数的
// 例如: 1(1), 4(1, 2, 4), 9(1, 3, 9), 16(1, 4, 16)...
// 因此只要找到n以内的完全平方数的个数即可.
int bulbSwitch(int n)
{
    if (n <= 0) return 0;
    return static_cast<int>(std::sqrt(n));  
}
