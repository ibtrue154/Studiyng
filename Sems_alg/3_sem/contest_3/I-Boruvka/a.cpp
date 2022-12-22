#include <iostream>
#include <vector>

using namespace std;

typedef struct Edge{
    int src, dest, weight;
}edge;

typedef struct Graph{
    int v, e;
    edge* edges;
}graph;

typedef struct Subset{
    int par, rank;
}subset;

graph* createGraph(int V, int E)
{
    graph* graph = new Graph;
    graph->v = V;
    graph->e = E;
    graph->edges = new edge[E];
    return graph;
}

int find(subset subsets[], int i)
{
    if (subsets[i].par != i)
        subsets[i].par = find(subsets, subsets[i].par);
  
    return subsets[i].par;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
  
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].par = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].par = xroot;
  
    else
    {
        subsets[yroot].par = xroot;
        subsets[xroot].rank++;
    }
}

void boruvkaMST(struct Graph* graph)
{
    int V = graph->v, E = graph->e;
    Edge *edge = graph->edges;
  
    subset *subsets = new subset[V];
  
    int *cheapest = new int[V];
  
    for (int v = 0; v < V; ++v)
    {
        subsets[v].par = v;
        subsets[v].rank = 0;
        cheapest[v] = -1;
    }
  
    int numTrees = V;
    int MSTweight = 0;
  
    while (numTrees > 1)
    {
        for (int v = 0; v < V; ++v)
           cheapest[v] = -1;

        for (int i = 0; i < E; i++)
        {
            int set1 = find(subsets, edge[i].src);
            int set2 = find(subsets, edge[i].dest);
  
            if (set1 == set2)
                continue;

            else
            {
               if (cheapest[set1] == -1 ||
                   edge[cheapest[set1]].weight > edge[i].weight)
                 cheapest[set1] = i;
  
               if (cheapest[set2] == -1 ||
                   edge[cheapest[set2]].weight > edge[i].weight)
                 cheapest[set2] = i;
            }
        }
  
        for (int i = 0; i < V; i++)
        {
            if (cheapest[i] != -1)
            {
                int set1 = find(subsets, edge[cheapest[i]].src);
                int set2 = find(subsets, edge[cheapest[i]].dest);
  
                if (set1 == set2)
                    continue;
                MSTweight += edge[cheapest[i]].weight;
  
                Union(subsets, set1, set2);
                numTrees--;
            }
        }
    }
  
    cout << MSTweight << endl;
    return;
}

int main()
{
    int n = 0, m = 0, s = 0, d = 0, w = 0;
    cin >> n >> m;
    graph* g = createGraph(n, m);
    for (int i = 0; i < m; i++)
    {
        cin >> s >> d >> w;
        g->edges[i].src = s - 1;
        g->edges[i].dest = d - 1;
        g->edges[i].weight = w;
    }

    boruvkaMST(g);

    return 0;
}