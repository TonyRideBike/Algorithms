/**
    POJ 1154 Letters
    SW Cert. week 5
    Depth-First Search

    244k 47ms
    */

#include <iostream>
#include <vector>

#define DEBUG1 1

#ifdef DEBUG1
#include <cstdio>
#endif // DEBUG1

using namespace std;

void findMaxSteps(int x, int y, int step);

static int R, C;
static vector<char> rec;
bool visited[26];
static int maxSteps;
static int move[2][4] = { { 1, 0, -1, 0 },     // move left or right
{ 0, 1, 0, -1 } };     // move up or down

int main()
{
#if DEBUG1
    freopen("SRCG5.in", "r", stdin);
#endif // DEBUG1

    cin >> R >> C;
    for (int i = 0; i < R*C; ++i)
    {
        char c;
        cin >> c;
        rec.push_back(vector<char>::value_type(c));
    }
    visited[rec[0] - 'A'] = true;
    findMaxSteps(0, 0, 1);
    cout << maxSteps << endl;
    return 0;
}

void findMaxSteps(int r, int c, int depth)
{
    /** Recursive approach of Depth-First Search
    Pseudocode:
    label v as discovered
    for all edges from v to w in G.adjacentEdges(v) do
    if vertex w is not labeled as discovered then
    recursively call DFS
    */
    maxSteps = maxSteps > depth ? maxSteps : depth;
    for (int i = 0; i < 4; i++)
    {
        int a = r + move[0][i], b = c + move[1][i];
        if (a >= 0 && a < R && b >= 0 && b < C && !visited[rec[a * C + b] - 'A'])
        {
            visited[rec[a * C + b] - 'A'] = true;
            findMaxSteps(a, b, depth + 1);
            visited[rec[a * C + b] - 'A'] = false;
        }
    }

}
