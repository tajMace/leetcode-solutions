// Roman to Integer (Easy)
// https://leetcode.com/problems/roman-to-integer/
// question_id: 13

/* ---------- SOLUTION START ---------- */

#include <cassert>
using namespace std;
#include <string>

class Solution {
public:
    int romanToInt(string s) {

        int result = 0;
        int prev = 'I';
        for (int i = s.length() - 1; i >= 0; i--) {
            switch (s[i]) {
                case 'I': /* 1 */
                    result += (prev == 'V' || prev == 'X') ? -1 : 1;
                    break;
                case 'V': /* 5 */
                    result += 5;
                    break;
                case 'X': /* 10 */
                    result += (prev == 'L' || prev == 'C') ? -10 : 10;
                    break;
                case 'L' : /* 50 */
                    result += 50;
                    break;
                case 'C': /* 100 */
                    result += (prev == 'D' || prev == 'M') ? -100 : 100;
                    break;
                case 'D': /* 500 */
                    result += 500;
                    break;
                case 'M': /* 1000 */
                    result += 1000;
                    break;
                default:
                    assert(1 == 0); /* shouldn't get here */
                    break;
            }

            prev = s[i];
        }

        return result;
    }
};
