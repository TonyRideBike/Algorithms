/**
    POJ 1125 Stockbroker Grapevine
    SW Cert. week 2
    Floyd Algorithm

    168k 0ms
    */

#include <stdio.h>
#include <stdlib.h>

#define debug1 1
#define debug2 0

#define MAX_NODES       101
#define INF             0x7fff

int main(int argc, char *argv[]) {
#if debug1
    freopen("1125.in", "r", stdin);
#endif
    int nodes;
    scanf("%d", &nodes);
    while (nodes) {
        // solve cases
        int distance[MAX_NODES][MAX_NODES];
        for (int from = 1; from <= nodes; from++) {        // initialize tables
            for (int to = 1; to <= nodes; to++) {
                if (from == to) {
                    distance[from][to] = 0;
                }
                else {
                    distance[from][to] = INF;
                }
            }
        }

        for (int from = 1; from <= nodes; from++) {     // build the table
            int connections;
            scanf("%d", &connections);
            while (connections--) {
                int to, cost;
                scanf("%d %d", &to, &cost);
                distance[from][to] = cost;
            }
        } // build the table

#if debug2
        // check the table
        for (int from = 1; from <= nodes; from++) {
            for (int to = 1; to <= nodes; to++) {
                distance[from][to] == INF ? printf(" X ") : printf("%2d ", distance[from][to]);
            }
            printf("\n");
        }
        printf("\n");
#endif
        // Floyd algorithm O(N^3)
        for (int trans = 1; trans <= nodes; trans++) {
            for (int from = 1; from <= nodes; from++) {
                for (int to = 1; to <= nodes; to++) {
                    if (distance[from][to] > distance[from][trans] + distance[trans][to]) {
                        distance[from][to] = distance[from][trans] + distance[trans][to];
                    }
                }
            }
        }

#if debug2
        // check the map
        for (int from = 1; from <= nodes; from++) {
            for (int to = 1; to <= nodes; to++) {
                distance[from][to] == INF ? printf(" X ") : printf("%2d ", distance[from][to]);
            }
            printf("\n");
        }
        printf("\n");
#endif

        int from = 0, cost = INF;
        for (int i = 1; i <= nodes; i++) {
            int max = 0;
            for (int j = 1; j <= nodes; j++) {
                max = distance[i][j] > max ? distance[i][j] : max;
            }
            if (max < cost) {
                cost = max;
                from = i;
            }
        }

        printf("%d %d\n", from, cost);

        scanf("%d", &nodes);
    }
    return 0;
}
