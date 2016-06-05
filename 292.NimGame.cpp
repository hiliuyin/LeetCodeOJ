/*
You are playing the following Nim Game with your friend: 
There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. 
The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. 
Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: 
no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
*/

// 1 2 3必胜
// 4 必败
// 5 6 7必胜
// 8 必败
// 9 10 11必胜 ...
// 只要保证把必败策略留给对手即可，即把4的整数倍留给对手

class Solution {
public:
    bool canWinNim(int n) {
        if (n < 0) return false;
        
        return !(n%4 == 0);
    }
};
