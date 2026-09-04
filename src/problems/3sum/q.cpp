// 3Sum (Medium)
// https://leetcode.com/problems/3sum/
// question_id: 15

/* ---------- SOLUTION START ---------- */

using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        // for each value (ignore second to last: will be counted by all prev)
        for (int targetIdx = 0; targetIdx < size - 2; targetIdx++) {

            // skip starting duplicates
            if (targetIdx > 0 && nums[targetIdx] == nums[targetIdx - 1]) continue;

            // iterate only from target + 1: former have already been found
            int leftIdx = targetIdx + 1;
            int rightIdx = size - 1;

            while (leftIdx < rightIdx) {
                int sum = nums[targetIdx] + nums[leftIdx] + nums[rightIdx];
                if (sum < 0) { leftIdx++; continue; }
                if (sum > 0) { rightIdx--; continue; }

                ret.push_back({nums[targetIdx], nums[leftIdx], nums[rightIdx]});

                // skip all duplicate entries
                while (leftIdx < rightIdx && nums[leftIdx] == nums[leftIdx + 1]) leftIdx++;
                while (rightIdx > leftIdx && nums[rightIdx] == nums[rightIdx - 1]) rightIdx--;
                leftIdx++;
                rightIdx--;
            }
        }

        return ret;
    }
};
