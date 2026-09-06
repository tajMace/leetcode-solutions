// Integer to Roman (Medium)
// https://leetcode.com/problems/integer-to-roman/
// question_id: 12

/* ---------- SOLUTION START ---------- */

using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string intToRoman(int num) {
        vector<vector<string>> tables {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // ones
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // tens
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // hundreds,
            {"", "M", "MM", "MMM"}                                        // thousands
        };

        string result;
        int power = 0;
        while (num > 0) {
            result = tables[power][num % 10] + result;
            num /= 10;
            power++;
        }

        return result;
    }
};
