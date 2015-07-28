/**
    POJ 3278 Catch That Cow
    SW Cert. week3
    Breadth-First Search

    1388kB 313ms
    */

#include <stdio.h>
#include <stdlib.h>

#define MAX        100001

#define DEBUG1     1

int BFS(int from, int to);
int visited[MAX];

struct node{
    int position;
    int counter;
    struct node *next;
};

int main() {
#if DEBUG1
    freopen("3278.in", "r", stdin);
#endif // DEBUG1
    int N, K;
    scanf("%d %d", &N, &K);
    if (N > K) {
        printf("%d", N - K);
    }
    else {
        printf("%d", BFS(N, K));
    }
    return 0;
}

int BFS(int from, int to) {
    visited[from] = 1;
    struct node *queue_head = (struct node *)malloc(sizeof(struct node));
    struct node *queue_tail = queue_head;
    queue_tail->counter = 0;
    queue_tail->position = from;
    queue_tail->next = NULL;

    while (queue_head != NULL) {
        if (queue_head->position != to) {
            // check one step ahead or time limit exceeded.
            if (queue_head->position - 1 == to || queue_head->position + 1 == to || queue_head->position * 2 == to) {
                return queue_head->counter + 1;
            }

            // put next possible step into the queue
            if (queue_head->position - 1 >= 0 && !visited[queue_head->position - 1]) {
                // try -1
                queue_tail->next = (struct node *)malloc(sizeof(struct node));
                queue_tail->next->counter = queue_head->counter + 1;
                queue_tail->next->position = queue_head->position - 1;
                queue_tail->next->next = NULL;
                queue_tail = queue_tail->next;
                visited[queue_tail->position] = 1;
            }
            if (queue_head->position + 1 < MAX && !visited[queue_head->position + 1]) {
                // try +1
                queue_tail->next = (struct node *)malloc(sizeof(struct node));
                queue_tail->next->counter = queue_head->counter + 1;
                queue_tail->next->position = queue_head->position + 1;
                queue_tail->next->next = NULL;
                queue_tail = queue_tail->next;
                visited[queue_tail->position] = 1;
            }
            if (queue_head->position != 0 && queue_head->position * 2 < MAX && !visited[queue_head->position * 2]) {
                // try transport
                queue_tail->next = (struct node *)malloc(sizeof(struct node));
                queue_tail->next->counter = queue_head->counter + 1;
                queue_tail->next->position = queue_head->position * 2;
                queue_tail->next->next = NULL;
                queue_tail = queue_tail->next;
                visited[queue_tail->position] = 1;
            }

            // pop out the head
            struct node *temp = queue_head;
            queue_head = queue_head->next;
            free(temp);
        }
        else {
            return queue_head->counter;
        }
    }
    return 0;
}

