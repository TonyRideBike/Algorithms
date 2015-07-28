/*
    POJ 2823 Sliding Window
    SW Cert. week 7

    10964k 5375ms
    */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#pragma warning(disable:4996)

#define MAX 1000000

int numbers[MAX];
int maxArray[MAX];
int minArray[MAX];
int deQueue[MAX];
int inQueue[MAX];

int main()
{
    freopen("2823.in", "r", stdin);
    int size, window;
    scanf("%d %d", &size, &window);
    int i;
    int deFront = 0, deRear = 0, inFront = 0, inRear = 0;

    for (i = 0; i < size; ++i)
    {
        scanf("%d", &numbers[i]);
    }
    for (i = 0; i < size; ++i)
    {
        deQueue[deRear] = i;
        inQueue[inRear] = i;

        while (numbers[i] > numbers[deQueue[deRear - 1]] && deRear > deFront)
        {
            deRear--;
        }
        deQueue[deRear++] = i;
        if (deQueue[deFront] < i - window + 1)
        {
            deFront++;
        }

        while (numbers[i] < numbers[inQueue[inRear - 1]] && inRear > inFront)
        {
            inRear--;
        }
        inQueue[inRear++] = i;
        if (inQueue[inFront] < i - window + 1)
        {
            inFront++;
        }

        if (i >= window - 1)
        {
            maxArray[i - window + 1] = numbers[deQueue[deFront]];
            minArray[i - window + 1] = numbers[inQueue[inFront]];
        }
    }
    for (i = 0; i < (size - window + 1); ++i)
    {
        printf("%d ", minArray[i]);
    }
    printf("\n");
    for (i = 0; i < (size - window + 1); ++i)
    {
        printf("%d ", maxArray[i]);
    }
    printf("\n");
    return 0;
}