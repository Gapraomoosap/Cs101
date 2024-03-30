#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> g, int s, vector<bool> v)
{
    stack<int> stack;
    stack.push(s);
    v[s] = true;
    while (!stack.empty())
    {
        int cur = stack.top();
        stack.pop();
        for (int i = 0; i < g.size(); i++)
        {
            if (g[cur][i] && !v[i])
            {
                stack.push(i);
                v[i] = true;
            }
        }
    }
    for (int i = 0; i < g.size(); i++)
    {
        if (v[i] == 0)
            cout << i + 1 << " ";
    }
    cout << endl;
}
int main()
{
    vector<vector<int>> g;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        g.push_back(vector<int>(n, 0));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            int t;
            cin >> t;
            if (t == 0)
                break;
            g[i][t - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int s;
        vector<bool> visited(g.size(), false);
        cin >> s;
        DFS(g, s - 1, visited);
    }
    return 0;
}