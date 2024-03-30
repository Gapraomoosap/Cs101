#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int floydWarshall(vector<pair<int, int>> adj[], int V, int flag[])
{
    int dist[V][V];
    int path[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = INF;
            path[i][j] = -1;
        }
    }
    for (int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            dist[i][x.first] = x.second;
            path[i][x.first] = i;
        }
    }
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    int t_f = 0;
    int min_sum = INT_MAX;
    int s_i = 0;
    for (int i = 0; i < V; i++)
    {
        int sum = 0;
        if (i == flag[t_f] && t_f < V)
        {
            t_f++;
            continue;
        }
        int t_fj = 0;
        for (int j = 0; j < V; j++)
        {
            if (j == flag[t_fj] && t_fj < V)
            {
                t_fj++;
                continue;
            }
            sum += dist[i][j];
        }
        if (min_sum > sum)
        {
            min_sum = sum;
            s_i = i;
        }
    }
    return s_i;
}
void add_edge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
void print_graph(vector<pair<int, int>> adj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto x : adj[i])
        {
            cout << "(" << x.first << ", " << x.second << ")";
        }
        cout << endl;
    }
}
void add_new_edge(vector<pair<int, int>> adj[], int flag[], int n, int f, int n_h)
{
    for (int i = 0; i < f; i++)
    {
        for (auto x : adj[flag[i]])
        {
            int u = flag[i];
            int v = x.first;
            int w = x.second;
            // check duplicate
            bool duplicate = false;
            for (auto y : adj[v])
            {
                if (y.first == n_h)
                {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate)
            {
                adj[v].push_back({n_h, w});
                adj[n_h].push_back({v, w});
            }
        }
    }
}
void copy_graph(vector<pair<int, int>> adj[], vector<pair<int, int>> adj_copy[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (auto x : adj[i])
        {
            adj_copy[i].push_back(x);
        }
    }
}
int main()
{
    int f, n;
    cin >> f >> n;
    int flag[f];
    for (int i = 0; i < f; i++)
    {
        cin >> flag[i];
        flag[i]--;
    }
    vector<pair<int, int>> adj[n];
    for (int j = 0; j < n; j++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(adj, a - 1, b - 1, w);
    }
    int t_f = 0;
    int min_sum = INT_MAX;
    int min_index;
    vector<pair<int, int>> adj_copy[n];
    copy_graph(adj, adj_copy, n);
    for (int i = 0; i < n; i++)
    {
        if (i == flag[t_f])
        {
            t_f++;
            continue;
        }
        add_new_edge(adj_copy, flag, n, f, i);
    }
    cout << floydWarshall(adj_copy, n, flag) + 1;
    return 0;
}