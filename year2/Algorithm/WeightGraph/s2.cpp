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
void prim(vector<pair<int, int>> adj[], int n, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    pq.push({0, src});
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        inMST[u] = true;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += key[i] - 1;
    }
    cout << sum << endl;
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
    prim(adj, n, 0);
    return 0;
}