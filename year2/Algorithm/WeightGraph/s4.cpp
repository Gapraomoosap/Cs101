#include <bits/stdc++.h>
using namespace std;
void add_edge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
void dijkstra(vector<pair<int, int>> adj[], int n, int src, int dest, int p)
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
    int count = 0;
    while (p > 0)
    {
        p = p - (-1 * dist[dest]);
        count++;
    }
    cout << count << endl;
}
void invert_graph(vector<pair<int, int>> adj[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (auto &x : adj[i])
        {
            x.second *= -1;
        }
    }
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
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(adj, a - 1, b - 1, w);
    }
    int src, dest, p;
    cin >> src >> dest >> p;
    invert_graph(adj, n);
    dijkstra(adj, n, src - 1, dest - 1, p);
    return 0;
}