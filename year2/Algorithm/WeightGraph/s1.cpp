#include <bits/stdc++.h>
using namespace std;
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
void dijkstra(vector<pair<int, int>> adj[], int n, int src, int dest)
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
    cout << dist[dest] << endl;
}
void add_edge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
int main()
{
    int c;
    cin >> c;
    int n, m, s, t;
    for (int i = 0; i < c; i++)
    {
        cin >> n >> m >> s >> t;
        vector<pair<int, int>> adj[n];
        for (int j = 0; j < m; j++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            add_edge(adj, a, b, w);
        }
        dijkstra(adj, n, s, t);
    }
    return 0;
}