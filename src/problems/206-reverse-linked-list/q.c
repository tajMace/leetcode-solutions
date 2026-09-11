// Reverse Linked List (Easy)
// https://leetcode.com/problems/reverse-linked-list/
// question_id: 206
//
// * Definition for singly-linked list.
#include <stdio.h>
struct ListNode {
        int val;
        struct ListNode* next;
};

/* ---------- SOLUTION START ---------- */

struct ListNode* recurseReverseList(struct ListNode* curr, struct ListNode* prev);

struct ListNode* reverseList(struct ListNode* head) { return recurseReverseList(head, NULL); }

struct ListNode* recurseReverseList(struct ListNode* curr, struct ListNode* prev) {
        if (curr == NULL) {
                return NULL;
        }

        if (curr->next == NULL) {
                curr->next = prev;
                return curr;
        }

        struct ListNode* next = curr->next;
        curr->next = prev;
        return recurseReverseList(next, curr);
}
