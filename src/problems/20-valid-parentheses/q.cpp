// Valid Parentheses (Easy)
// https://leetcode.com/problems/valid-parentheses/
// question_id: 20

using namespace std;
#include <string>
#include <stack>

/* ---------- SOLUTION START ---------- */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (auto &c : s) {
            if (isOpening(c)) {
                stack.push(c);
            } else if (stack.size() == 0 || !isMatching(stack.top(), c)) {
                return false;
            } else {
                stack.pop();
            }
        }

        return (stack.size() == 0) ? true : false;
    }

private:
    bool isOpening(char c) {
        return (c == '(' || c == '[' || c == '{');
    }

    bool isClosing(char c) {
        return !isOpening(c);
    }

    bool isMatching(char opening, char closing) {
        return (
            (opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}')
        );
    }
};
