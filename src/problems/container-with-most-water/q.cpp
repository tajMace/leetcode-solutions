// Container With Most Water (Medium)
// https://leetcode.com/problems/container-with-most-water/
// question_id: 11

/* ---------- SOLUTION START ---------- */

using namespace std;
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int leftPtr = 0;
        int rightPtr = height.size() - 1;

        while (leftPtr < rightPtr) {
            int currVolume = min(height[leftPtr], height[rightPtr]) * (rightPtr - leftPtr);
            ret = max(ret, currVolume);
            (height[leftPtr] < height[rightPtr]) ? leftPtr++ : rightPtr--;
        }

        return ret;
    }
};
