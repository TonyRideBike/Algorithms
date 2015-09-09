/**
    POJ 2485 Highways
    Prime

    612k 157ms
    */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
//#include <malloc.h>

#define MAX_VILLAGE 300
#define DEBUG 1

using namespace std;

int DISTANCE[300][300];
void MiniSpanTree_Prim(int n);
int answer;

int main()
{
#if DEBUG
    freopen("2485.in", "r", stdin);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < MAX_VILLAGE; i++)
        {
            for (int j = 0; j < MAX_VILLAGE; j++)
            {
                DISTANCE[i][j] = 0x7fffffff;    
            }
        }
        answer = 0;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &DISTANCE[i][j]);    
            }
        }
        MiniSpanTree_Prim(N);
        cout << answer << endl;
    }
}

void MiniSpanTree_Prim(int n)
{
    int min, i, j, k;
    int adjvex[MAX_VILLAGE];
    int lowcost[MAX_VILLAGE];
    lowcost[0] = 0;
    adjvex[0] = 0;
    for (i = 1; i < n; i++)
    {
        lowcost[i] = DISTANCE[0][i];
        adjvex[i] = 0;
    }
    for (i = 1; i < n; i++)
    {
#if DEBUG
        cout << "----------------" << endl;
        for (int x = 0; x < n; x++)
        {
            printf("%d\t", adjvex[x]);
        }
        cout << endl;
        for (int x = 0; x < n; x++)
        {
            printf("%d\t", lowcost[x]);
        }
        cout << endl;
        cout << "----------------" << endl;
#endif
        min = 0x7fffffff;
        j = 1;
        k = 0;
        while (j < n)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        //printf("(%d, %d)\n", adjvex[k]+1, k+1);
        answer = answer > DISTANCE[adjvex[k]][k] ? answer : DISTANCE[adjvex[k]][k];
        lowcost[k] = 0;
        for (j = 1; j < n; j++)
        {
            if (lowcost[j] != 0 && DISTANCE[k][j] < lowcost[j])
            {
                lowcost[j] = DISTANCE[k][j];
                adjvex[j] = k;
            }
        }
    }
}