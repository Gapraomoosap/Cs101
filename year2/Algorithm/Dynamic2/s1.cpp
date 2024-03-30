#include <bits/stdc++.h>
using namespace std;
int knapsackTD(int wt[], int val[], int n, int w, vector<vector<int>> &memo)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (memo[n][w] != -1)
    {
        return memo[n][w];
    }
    if (wt[n - 1] > w)
    {
        return memo[n][w] = knapsackTD(wt, val, n - 1, w, memo);
    }
    return memo[n][w] = max(val[n - 1] + knapsackTD(wt, val, n - 1, w - wt[n - 1], memo), knapsackTD(wt, val, n - 1, w, memo));
}
int main()
{
    int n = 4;
    int w = 18;
    int val[] = {12, 5, 4, 2};
    int wt[] = {8, 7, 4, 2};
    vector<vector<int>> memo(n + 1, vector<int>(w + 1, -1));
    cout << knapsackTD(wt, val, n, w, memo);
    return 0;
}