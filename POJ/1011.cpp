/*
    POJ 1011 Sticks
    
    */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STICKS 64

#define DEBUG1 1

struct node{
    int position;
    int counter;
    struct node *next;
 };

int main(int argc, char *argv[]) {
#if DEBUG1
    freopen("1011.in", "r", stdin);
#endif
    int sticks;
    scanf("%d", &sticks);
    while (sticks) {
        int lengths[MAX_STICKS] = {0};
        int max_length = 0;
        int min_length = 0x7fff;
        for (int i = 0; i < sticks; i++) {
            scanf("%d", &lengths[i]);
            max_length = max_length > lengths[i] ? max_length : lengths[i];
            min_length = min_length < lengths[i] ? min_length : lengths[i];
        }
        // TO-DO
        scanf("%d", &sticks);
    }
    return 0;
}