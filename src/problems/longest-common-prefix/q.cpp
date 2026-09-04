// Longest Common Prefix (Easy)
// https://leetcode.com/problems/longest-common-prefix/
// question_id: 14

/* ---------- SOLUTION START ---------- */

using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        if (strs.size() == 1) {
            return first;
        }

        int prefixLen = first.size();
        for (auto &str : strs) {
            for (int i = 0; i < prefixLen; i++) {

                // no common prefix check
                if (i == 0 && str[i] != first[i]) {
                    return "";
                }

                // not the same: break
                if (str[i] != first[i]) {
                    prefixLen = i;
                    break;
                }

                // finished string: matches but short
                if (i == str.length() - 1) {
                    prefixLen = i + 1;
                    break;
                }
            }
        }

        return first.substr(0, prefixLen);
    }
};
