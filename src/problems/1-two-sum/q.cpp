// Two Sum (Easy)
// https://leetcode.com/problems/two-sum/
// question_id: 1

using namespace std;
#include <vector>
#include <unordered_map>

/* ---------- SOLUTION START ---------- */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            // if compliment in map: answer
            auto it = map.find(target - num);
            if (it != map.end()) {
                return {it->second, i};
            }

            // else, add to set
            map[num] = i;
        }

        // should never get here.
        return {-1, -1};
    }
};
