#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& graph, int startVertex, vector<bool>& visited, int parent[]) {
    queue<int> queue;
    queue.push(startVertex);
    visited[startVertex] = true;
    parent[startVertex] = -1; 

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        for (int i = 0; i < graph[currentVertex].size(); ++i) {
            int neighbor = graph[currentVertex][i];
            if (!visited[neighbor]) {
                queue.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = currentVertex; 
            }
        }
    }
}

int shortest(int parent[], int startVertex, int endVertex) {
    int pathLength = 0;
    for (int v = endVertex; v != -1; v = parent[v]) {
        pathLength++;
        if (v == startVertex) {
            break;
        }
    }
    return pathLength;
}

int main() {
    int n;
    cin >> n;
    int x;
    int parent[n];
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        while (true) {
            cin >> x;
            if (x == -1) {
                break;
            }
            graph[i].push_back(x);
        }
    }

    int startVertex, endVertex;
    cin >> startVertex >> endVertex;

    BFS(graph, startVertex, visited, parent);

    cout << "Parent Array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Parent of node " << i << " is " << parent[i] << endl;
    }

    int length = shortest(parent, startVertex, endVertex);
    cout << "Shortest Path Length from " << startVertex << " to " << endVertex << " is " << length << endl;

    return 0;
}

