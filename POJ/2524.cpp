/**
    POJ 2524 Ubiquitous Religions
    Union Find

    368K 422ms
    */

#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <malloc.h>

using namespace std;

#define MAX_N 50000
#define DEBUG 1

int mark[MAX_N + 1];
int findFather(int a);

int main()
{
#if DEBUG
    freopen("2524.in", "r", stdin);
#endif
    int N, M;
    int case_count = 0;
    scanf("%d %d", &N, &M);
    while (!(N == 0 && M == 0))
    {
        case_count++;
        int answer = N;
        for (int i = 0; i < N + 1; i++)
        {
            mark[i] = i;
        }
        for (int k = 0; k < M; k++)
        {
            int i, j;
            scanf("%d %d", &i, &j);
            int a = findFather(i), b = findFather(j);
            if (a != b)
            {
                answer--;
                mark[b] = a;
            }
        }

        printf("Case %d: %d\n", case_count, answer);
        scanf("%d %d", &N, &M);
    }
    return 0;
}

int findFather(int a)
{
    if(mark[a] == a)
    {
        return a;
    }
    else
    {
        return findFather(mark[a]);
    }
}