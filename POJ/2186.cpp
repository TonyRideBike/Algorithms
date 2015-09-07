/**
    POJ 2186 Popular Cows
    SW Cert. week 8
    Strongly Connected Components

    WA
    */

#include <iostream>
#include <cstdio>
#include <cstdlib>

#define DEBUG 1
#ifdef DEBUG

#endif // DEBUG

#define MAX_COWS 10000
#define MAX_PAIR 50000

#define WHITE 0
#define GRAY 1
#define BLACK 2

struct node{
    int nodeNumber;
    struct node *next;
};

struct int_pair{
    int in;
    int out;
};

struct Graph
{
    int vertex;
    int edge;
    struct node *rootList;
    struct int_pair *IO_time;
    int *vertexColor;
};

int N_cows, M_relations;
static int iotime;

void DFS_visit(struct Graph *G, int i);
void DFS(struct Graph *G);
void STRONGLY_CONNECTED_COMPONENTS(struct Graph *G);
struct Graph * transformGraph(struct Graph *G);
void printGraph(struct Graph *G);

using namespace std;

int main()
{
    freopen("2186.in", "r", stdin);
    cin >> N_cows >> M_relations;
    struct Graph G;
    G.edge = M_relations;
    G.vertex = N_cows;
    G.rootList = (struct node *)malloc(sizeof(struct node) * (G.vertex + 1));
    G.vertexColor = (int *)malloc(sizeof(int) * (G.vertex + 1));
    G.IO_time = (struct int_pair *)malloc(sizeof(struct int_pair)
                                          * (G.vertex + 1));

    for (int i = 1; i < N_cows + 1; i++)
    {
        G.rootList[i].nodeNumber = 0;
        G.rootList[i].next = NULL;
    }
    for(int i = 0; i < M_relations; i++)
    {
        int a, b;
        cin >> a >> b;
        G.rootList[a].nodeNumber++;
        struct node *ptr = &(G.rootList[a]);
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = (struct node *)malloc(sizeof(struct node));
        ptr->next->nodeNumber = b;
        ptr->next->next = NULL;
    }

    STRONGLY_CONNECTED_COMPONENTS(&G);

    return 0;
}


void STRONGLY_CONNECTED_COMPONENTS(struct Graph *G)
{
    /**
    Pseudo-code by GoF:
    1 call DFS(G) to compute finishing time f[u] for each vertex u
    2 compute GT
    3 call DFS(GT). but in the main loop of DFS, consider the vertices in
    order of decreasing f[u](as computed in line 1)
    4 output the vertices of each tree in the depth-first forest formed in
    line 3 as a separate strongly connected component
    */
    DFS(G);
#if DEBUG
    printGraph(G);
#endif // DEBUG
    struct Graph *GT = transformGraph(G);
#if DEBUG
    cout << endl << "GT is :" << endl;
    printGraph(GT);
#endif // DEBUG

}

void DFS(struct Graph *G)
{
    /**
    Pseudo-code by GoF:
    1 for each vertex u in V[G]
    2     do color[u] = WHITE
    3        pi[u] = NIL
    4 time = 0
    5 for each vertex u in V[G]
    6     do if color[u] == WHITE
    7        then DFS-VISIT(u)
    */
    static int iotime = 0;
    for(int i = 1; i < N_cows + 1; i++)
    {
        G->vertexColor[i] = WHITE;
        G->IO_time[i].in = 0;
        G->IO_time[i].out = 0;
    }
    for(int i = 1; i < N_cows + 1; i++)
    {
        if(G->vertexColor[i] == WHITE)
        {
            DFS_visit(G, i);
        }
    }
}

void DFS_visit(struct Graph *G, int i)
{
    /**
    DFS-VISIT(u)
    1 color[u] = GRAY
    2 time++
    3 d[u] = time
    4 for each v in Adj[u]
    5     do if color[v] == WHITE
    6         then pi[v] = u
    7              DFS-VISIT(v)
    8 color[u] = BLACK
    9 f[u] = time = time + 1
    */
    G->vertexColor[i] = GRAY;
    iotime++;
    G->IO_time[i].in = iotime;
    struct node * ptr = G->rootList[i].next;
    while(ptr != NULL)
    {
        if(G->vertexColor[ptr->nodeNumber] == WHITE)
        {
            DFS_visit(G, ptr->nodeNumber);
        }
        ptr = ptr->next;
    }
    G->vertexColor[i] = BLACK;
    G->IO_time[i].out = ++iotime;
}

struct Graph * transformGraph(struct Graph * G)
{
    struct Graph *GT = (struct Graph *)malloc(sizeof(struct Graph));
    GT->edge = G->edge;
    GT->vertex = G->vertex;
    GT->rootList = (struct node *)malloc(sizeof(struct node)
                                         * (GT->vertex + 1));
    GT->vertexColor = (int *)malloc(sizeof(int) * (GT->vertex + 1));
    GT->IO_time = (struct int_pair *)malloc(sizeof(struct int_pair)
                                           * (GT->vertex + 1));
    for (int i = 1; i < N_cows + 1; i++)
    {
        GT->rootList[i].nodeNumber = 0;
        GT->rootList[i].next = NULL;
    }
    for (int i = 1; i < GT->vertex + 1; ++i)
    {
        struct node *ptr = G->rootList[i].next;
        struct node *ptrGT;
        while(ptr != NULL)
        {
            ptrGT = &(GT->rootList[ptr->nodeNumber]);
            GT->rootList[ptr->nodeNumber].nodeNumber++;
            while(ptrGT->next != NULL)
            {
                ptrGT = ptrGT->next;
            }
            ptrGT->next = (struct node *)malloc(sizeof(struct node));
            ptrGT->next->nodeNumber = i;
            ptrGT->next->next = NULL;
            ptr = ptr->next;
        }
    }
    return GT;
}

void printGraph(struct Graph * g)
{
    for (int i = 1; i < g->vertex + 1; ++i)
    {
        cout << "node " << i << " goes to: " << endl;
        struct node *ptr = g->rootList[i].next;
        while(ptr != NULL)
        {
            cout << " " << ptr->nodeNumber;
            ptr = ptr->next;
        }
        cout << endl;
        cout << " in: "<< g->IO_time[i].in;
        cout << " out: " << g->IO_time[i].out << endl;
    }
}
