// Letter Combinations of a Phone Number (Medium)
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// question_id: 17

/* ---------- SOLUTION START ---------- */

using namespace std;

#include <string>
#include <vector>
#include <cstdlib>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const string mapping[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ret = {""};

        for (auto &digit : digits) {
            string digitBucket = mapping[digit - '0'];
            vector<string> tmp;

            for (auto &part : ret) {
                for (auto &val : digitBucket) {
                    tmp.push_back(part + val);
                }
            }

            ret = std::move(tmp);
        }

        return ret;
    }
};


/**
 * for (digit in input) {
 *  ret.map(str => ...{str + map[digit][0], str + map[digit][1], str + map[digit][2]})
 * }
 */

// ret = { "a", "b", "c"}
// ret = {"ad", "ae", "af", "bd", "be", "bf", "g"}
