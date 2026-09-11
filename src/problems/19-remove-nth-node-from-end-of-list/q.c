// Remove Nth Node From End of List (Medium)
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// question_id: 19
//
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

/* ---------- SOLUTION START ---------- */

void removeNth(struct ListNode* curr, int* count, int n);

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head->next == NULL) return NULL;

    int count = 0;
    struct ListNode dummy;
    dummy.next = head;

    removeNth(&dummy, &count, n);

    return dummy.next;
}

void removeNth(struct ListNode* curr, int* count, int n) {
    if (curr == NULL) return;

    // traverse to end of list
    removeNth(curr->next, count, n);

    (*count)++;

    // remove node if target
    if ((*count) == n + 1) {
        struct ListNode* temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
}
