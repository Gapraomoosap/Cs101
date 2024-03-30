#include <bits/stdc++.h>
using namespace std;
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
int dijkstra(vector<pair<int, int>> adj[], int n, int src, int flag[], int f)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> intree(n, false);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        intree[u] = true;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (intree[v] == false && dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    int sum = 0;
    int t_f = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == flag[t_f] && t_f < f)
        {
            t_f++;
            continue;
        }
        sum += dist[i];
    }
    return sum;
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
    for (int i = 0; i < n; i++)
    {
        if (i == flag[t_f])
        {
            t_f++;
            continue;
        }
        vector<pair<int, int>> adj_copy[n];
        copy_graph(adj, adj_copy, n);
        add_new_edge(adj_copy, flag, n, f, i);
        int sum = dijkstra(adj_copy, n, i, flag, f);
        if (min_sum > sum)
        {
            min_sum = sum;
            min_index = i + 1;
        }
    }
    cout << min_index;
    return 0;
}