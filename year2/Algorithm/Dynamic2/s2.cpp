#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define V 5
void Path(int path[V][V], int u, int v)
{
    if (u == v)
    {
        cout << u << " ";
        return;
    }
    if (path[u][v] == -1)
    {
        cout << "No path";
        return;
    }
    else
    {
        Path(path, u, path[u][v]);
        cout << v << " ";
    }
}
void floydWarshall(int graph[V][V])
{
    int dist[V][V];
    int path[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j || graph[i][j] == INF)
            {
                path[i][j] = -1;
            }
            else
            {
                path[i][j] = i;
            }
        }
    }
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    Path(path, 0, 4);
}
int main()
{
    int graph[5][5] = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}};
    floydWarshall(graph);
    return 0;
}