// Maximum Depth of Binary Tree (Easy)
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// question_id: 104

using namespace std;
#include <queue>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* ---------- SOLUTION START ---------- */


class Solution {
public:
    int maxDepth(TreeNode* root) {
        return recurse(root);
    }

private:
    int recurse(TreeNode* curr) {
        if (!curr) {
            return 0;
        }

        int maxLeft = recurse(curr->left);
        int maxRight = recurse(curr->right);

        return max(maxLeft, maxRight) + 1;
    }
};
