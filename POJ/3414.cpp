/**
 * POJ 3414
 *
 */

#include <iostream>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <string>

#define DEBUG1 1

using namespace std;

struct node {
    int A, B;
    int step;
    string op;
    struct node *prev;
    struct node *next;
};

int main()
{
#if DEBUG1
    freopen("3414.in", "r", stdin);
#endif // DEBUG1
    int A, B, C;
    cin >> A >> B >> C;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tail;
    tail = head;
    tail->A = A;
    tail->B = B;
    tail->op = "";
    tail->step = 0;
    tail->prev = NULL;
    tail->next = NULL;
    while (1)
    {
        if (tail->A == C || tail->B == C);
    }
    return 0;
}

void fill(*int a, *int b, int A, int B)
{

}
