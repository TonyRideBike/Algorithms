/**
    POJ 2531 Network Saboteur
    SW Cert. week 5 bonus
    Depth-First Search

    WA
    */

#include <iostream>

#define DEBUG 1

#ifdef DEBUG
#include <cstdio>
#endif // DEBUG

using namespace std;

static int nodes;
static int traffic[20][20];
static bool chosen[20];
static long maxTraffic;

void findMaxTraffic(int depth, int nodeX, int trafficSum);

int main()
{
#ifdef DEBUG
    freopen("2531.in", "r", stdin);
#endif // DEBUG

    cin >> nodes;
    for (int i = 0; i < nodes; ++i)
    {
        for (int j = 0; j < nodes; ++j)
        {
            cin >> traffic[i][j];
        }
    }
    chosen[0] = true;
    findMaxTraffic(1, 0, 0);
    cout << maxTraffic << endl;
}

void findMaxTraffic(int depth, int nodeX, int trafficSum)
{
    /** Recursive approach of Depth-First Search
    Pseudocode:
    label v as discovered
    for all edges from v to w in G.adjacentEdges(v) do
        if vertex w is not labeled as discovered then
        recursively call DFS

    */
    if (depth >= 20)
        return;
    maxTraffic = maxTraffic > trafficSum ? maxTraffic : trafficSum;
    for (int i = 0; i < nodes; ++i)
    {
        if (!chosen[i])
        {
            chosen[i] = true;

            chosen[i] = false;
        }
    }
}
