#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

void Dijkstra(vector<vector<pair<int, int>>> &adj, int src, int V) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V = 9;
    vector<vector<pair<int, int>>> adj(V);

    // Add edges to the graph. For example:
    // adj[0].push_back(make_pair(1, 4));
    // adj[0].push_back(make_pair(7, 8));
    // ...

    Dijkstra(adj, 0, V);

    return 0;
}