/*
    POJ 3614 Sunscreen
    SW Cert. week 7 bonus
    Greedy Algorithm

    WA
    */

#include <cstdio>
#include <cstdlib>
#include <malloc.h>
#include <iostream>

using namespace std;

#pragma warning(disable:4996)

struct intPair{
    int first;
    int second;
};

void quickSort_intPair(struct intPair *array, int low, int high);
int partition(struct intPair *array, int low, int high);

int main()
{
    freopen("3614.in", "r", stdin);
    int C, L;
    cin >> C >> L;
    struct intPair * cows = (struct intPair *)malloc(sizeof(struct intPair) * C);
    struct intPair * lotions = (struct intPair *)malloc(sizeof(struct intPair) * L);
    for (int i = 0; i < C; i++)
    {
        cin >> cows[i].first >> cows[i].second;
    }
    for (int i = 0; i < L; i++)
    {
        cin >> lotions[i].first >> lotions[i].second;
    }

    quickSort_intPair(cows, 0, C - 1);
    quickSort_intPair(lotions, 0, L - 1);

    int answer;
    for (int i = 0; i < C; i++)
    {
        // TO-DO
    }
    return 0;
}

void quickSort_intPair(struct intPair *array, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(array, low, high);

        quickSort_intPair(array, low, pivot - 1);
        quickSort_intPair(array, pivot + 1, high);
    }
}

int partition(struct intPair *array, int low, int high)
{
    int pivotKey;
    pivotKey = array[low].first;
    while (low < high)
    {
        while (low < high && array[high].first >= pivotKey)
        {
            high--;
        }
        swap(array, low, high);
        while (low < high && array[low].first <= pivotKey)
        {
            low++;
        }
        swap(array, low, high);
    }
    return low;
}

void swap(struct intPair *array, int a, int b)
{
    struct intPair temp;
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}