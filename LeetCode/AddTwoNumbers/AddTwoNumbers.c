#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* list) {
    printf("list: ");
    while (1) {
        printf("%d", list->val);
        if (list->next != NULL) {
            printf(" -> ");
            list = list->next;
        } else break;
    }
    printf("\n");
}

struct ListNode* numberToNodes(long long number) {
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cusor = l1;
    while (1) {
        cusor->val = number % 10;
        number = number / 10;
        if (number > 0) {
            cusor->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cusor->next->next = NULL;
            cusor = cusor->next;
        } else break;
    }
    return l1;
}

long long nodesToNumber(struct ListNode* list) {
    int digit = 1;
    long long number = 0;
    while (1) {
        number += (list->val * digit);
        if (list->next != NULL) {
            digit *= 10;
            list = list->next;
        } else break;
    }
    return number;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int flag = 0;
    struct ListNode* cusor = l1;
    while (1) {
        cusor->val = cusor->val + l2->val + flag;
        if (cusor->val > 9) {
            flag = 1;
            cusor->val = cusor->val % 10;
        } else {
            flag = 0;
        }
        
        if (cusor->next == NULL && l2->next == NULL && flag == 0) {
            break;
        }
        
        if (cusor->next == NULL && (l2->next != NULL || flag == 1)) {
            cusor->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cusor->next->val = 0;
            cusor->next->next = NULL;
        }
        cusor = cusor->next;
        if (l2->next == NULL) {
            l2->val = 0;
        } else {
            l2 = l2->next;
        }
    }
    return l1;
}

int main(int argc, char *argv[]) {
    printList(addTwoNumbers(numberToNodes(99), numberToNodes(99)));
    //printf("%lld", nodesToNumber(addTwoNumbers(numberToNodes(9), numberToNodes(9999999991))));
    return 0;
}
