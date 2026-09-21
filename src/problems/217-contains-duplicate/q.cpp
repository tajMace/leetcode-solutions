// Contains Duplicate (Easy)
// https://leetcode.com/problems/contains-duplicate/
// question_id: 217

using namespace std;
#include <vector>
#include <unordered_set>

/* ---------- SOLUTION START ---------- */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (auto &num : nums) {
            // check if in set
            auto it = s.find(num);
            if (it != s.end()) {
                return true;
            }

            // else, add it.
            s.insert(num);
        }

        // must all be unique
        return false;
    }
};
