/**
    POJ 2531 Network Saboteur
    SW Cert. week 5 bonus
    Depth-First Search

    WA
    */

#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX_NODES 20

#ifdef DEBUG
#include <cstdio>
#endif // DEBUG

using namespace std;

static int nodes;
static int fullTraffic;
static int trafficTable[MAX_NODES][MAX_NODES];
static bool chosen[MAX_NODES];
static long maxTraffic;

void findMaxTraffic(int depth, int nodeX, int traffic);

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
            cin >> trafficTable[i][j];
            fullTraffic += trafficTable[i][j];
        }
    }
    chosen[0] = true;
    findMaxTraffic(1, 0, 0);
    cout << maxTraffic << endl;
}

void findMaxTraffic(int depth, int nodeX, int traffic)
{
    /** 
    Recursive approach of Depth-First Search
    Pseudo-code:
    label v as discovered
    for all edges from v to w in G.adjacentEdges(v) do
    ____if vertex w is not labeled as discovered then
    ____recursively call DFS

    */
    int t = traffic;
    if (depth >= 20)
        return;
    for (int i = 0; i < MAX_NODES; i++)
    {
        if (chosen[i])
        {
            t -= trafficTable[nodeX][i];
        }
        else if (!chosen[i])
        {
            t += trafficTable[nodeX][i];
        }
    }
    maxTraffic = maxTraffic > t ? maxTraffic : t;
    chosen[nodeX + 1] = true;
    findMaxTraffic(depth + 1, nodeX + 1, t);
    chosen[nodeX + 1] = false;
    findMaxTraffic(depth + 1, nodeX + 1, t);
}

