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
    int i_looper = 0, j_looper = 0;
    int map[MAX_CITIES][MAX_CITIES] = {INF};
    scanf("%d %d", &cities, &roads);
    for(i_looper = 0; i_looper < MAX_CITIES; i_looper++)
    {
        for (j_looper = 0; j_looper < MAX_CITIES; j_looper++)
        {
            if (j_looper == i_looper)
            {
                map[i_looper][j_looper] = 0;
            }
            else
            {
                map[i_looper][j_looper] = INF;
            }
        }
    }
    for (i_looper = 0; i_looper < roads; ++i_looper)
    {
        int i, j, length;
        scanf("%d %d %d", &i, &j, &length);
        map[i][j] = length;
        map[j][i] = length;
    }

    for(i_looper = 1; i_looper <= cities; i_looper++)
    {
        for (j_looper = 1; j_looper <= cities; j_looper++)
        {
            if (map[i_looper][j_looper] == INF)
            {
                printf(" X ");
            }
            else
            {
                printf("%2d ", map[i_looper][j_looper]);
            }
        }
        printf("\n");
    }

    //to-do
    return 0;
}