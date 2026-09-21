// Design Linked List (Medium)
// https://leetcode.com/problems/design-linked-list/
// question_id: 838

#include <stdlib.h>
#include <stdio.h>

/* ---------- SOLUTION START ---------- */

struct Node {
    int val;
    struct Node *next;
};

typedef struct {
    struct Node *head;
    struct Node *tail;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *new = malloc(sizeof(MyLinkedList));
    if (!new) {
        return NULL; /* op failure */
    }

    (*new) = (MyLinkedList){
        .head = NULL,
        .tail = NULL
    };

    return new;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    struct Node *curr = obj->head;
    int count = 0;
    while (count < index && curr != NULL) {
        curr = curr->next;
        count++;
    }

    // index out of bounds
    if (curr == NULL) {
        return -1;
    }

    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct Node *new = malloc(sizeof(struct Node));
    if (!new) {
        return; /* no-op failure */
    }

    (*new) = (struct Node){
        .val = val,
        .next = (obj->head) ? obj->head : NULL
    };

    obj->head = new;
    if (obj->tail == NULL) {
        obj->tail = new;
    }
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct Node *new = malloc(sizeof(struct Node));
    if (!new) {
        return; /* no-op failure */
    }

    (*new) = (struct Node){
        .val = val,
        .next = NULL
    };

    if (obj->tail != NULL) {
        obj->tail->next = new;
    }

    obj->tail = new;

    if (obj->head == NULL) {
        obj->head = new;
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    struct Node *curr = obj->head;
    if (curr == NULL) {
        return; /* early return: certainly invalid */
    }

    int currIdx = 1;
    while (curr->next != NULL && currIdx < index) {
        curr = curr->next;
        currIdx++;
    }

    // index out of bounds
    if (curr->next == NULL && currIdx != index) {
        return;
    }

    // insert into list: potentially at the end
    struct Node *new = malloc(sizeof(struct Node));
    if (!new) return;
    *new = (struct Node){ .val = val, .next = NULL };

    if (curr->next == NULL) {
        obj->tail->next = new;
        obj->tail = new;
    } else {
        new->next = curr->next;
        curr->next = new;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (obj->head == NULL) {
        return;
    }

    if (index == 0) {
        struct Node *temp = obj->head;
        obj->head = obj->head->next;
        if (obj->head == NULL) {
            obj->tail = NULL;
        }
        free(temp);

        return;
    }

    struct Node *curr = obj->head;

    int currIdx = 1;
    while (curr->next != NULL && currIdx < index) {
        curr = curr->next;
        currIdx++;
    }

    // index out of bounds
    if (curr->next == NULL || currIdx != index) {
        return;
    }

    struct Node *temp = curr->next;

    curr->next = curr->next->next;
    free(temp);

    if (curr->next == NULL) {
        obj->tail = curr;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    struct Node *curr = obj->head;
    struct Node *temp = NULL;
    while (curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }

    free(obj);
}
