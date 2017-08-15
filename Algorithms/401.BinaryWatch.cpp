/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.

For example, the above binary watch reads "3:25".
Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/

std::vector<std::string> readBinaryWatch(int num) {
    std::vector<int> h{1, 2, 4, 8};
    std::vector<int> m{1, 2, 4, 8, 16, 32};
    std::vector<int> hours;
    std::vector<int> minutes;
    
    std::function<void(int, int, int)> getHour = [&](int beg, int val, int count) {
        if (val > 11) return;
        if (count == 0) {
            hours.emplace_back(val);
            return;
        }
        for (int i = beg; i < h.size(); ++i) {
            getHour(i + 1, val + h[i], count - 1);
        }
    };
    
    std::function<void(int, int, int)> getMinute = [&](int beg, int val, int count) {
        if (val > 59) return;
        if (count == 0) {
            minutes.emplace_back(val);
            return;
        }
        for (int i = beg; i < m.size(); ++i) {
            getMinute(i + 1, val + m[i], count - 1);
        }
    };
    
    std::vector<std::string> res;
    for (int i = 0, iEnd = std::min(num, 3); i <= iEnd; ++i) {
        getHour(0, 0, i);
        getMinute(0, 0, num-i);
        for (int i = 0; i < hours.size(); ++i) {
            for (int j = 0; j < minutes.size(); ++j) {
                res.emplace_back(std::to_string(hours[i]) + ":" + (minutes[j] < 10 ? "0" : "") + std::to_string(minutes[j]));
            }
        }
        hours.clear();
        minutes.clear();
    }
    
    return res;
}
