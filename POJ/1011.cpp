/*
    POJ 1011 Sticks

    */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int position;
    int counter;
    struct node *next;
 };

int main(int argc, char *argv[])
{
    freopen("1011.in", "r", stdin);
    int sticks;
    scanf("%d", &sticks);
    while (sticks != 0)
    {
        int *lengths = (int *)malloc(sizeof(int) * sticks);
        int max_length = 0;
        for (int i = 0; i < sticks; i++)
        {
            scanf("%d", &lengths[i]);
            max_length = max_length > lengths[i] ? max_length : lengths[i];
        }
        int *marker = (int *)malloc(sizeof(int) * (max_length + 1));
        scanf("%d", &sticks);
    }
    return 0;
}