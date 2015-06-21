/***
 * OJ 1024 in C programming language
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define DEBUG1      1

#define MAX_CITIES  201
#define INF         0x7fff

int main ()
{
#if DEBUG1
    freopen("1024.in", "r", stdin);
    freopen("1024.out", "w", stdout);
#endif
    int cities, roads;
    int loop_i = 0, loop_j = 0;
    int map[MAX_CITIES][MAX_CITIES] = {INF};
    scanf("%d %d", &cities, &roads);
    for (loop_i = 0; loop_i < MAX_CITIES; ++loop_i)
    {
        map[loop_i][loop_i] = 0;
    }
    for (loop_i = 0; loop_i < roads; ++loop_i)
    {
        int i, j, length;
        scanf("%d %d %d", &i, &j, &length);
        map[i][j] = length;
        map[j][i] = length;
    }
    for(loop_i = 1; loop_i <= cities; loop_i++)
    {
        for (loop_j = 1; loop_i <= cities; loop_j++)
        {
            printf("%2d ", map[loop_i][loop_j]);
        }
        printf("\n");
    }
    return 0;
}