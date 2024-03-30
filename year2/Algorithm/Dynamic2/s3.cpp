#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int cost(int arr[][3], int n, int m)
{
    return arr[n][m];
}
int minPathSum(int arr[][3], vector<vector<int>> &memo, int n, int m)
{
    if (n < 0 || m < 0)
    {
        return INF;
    }
    if (memo[n][m] != -1)
    {
        return memo[n][m];
    }
    if (n == 0 && m == 0)
    {
        return memo[n][m] = cost(arr, n, m);
    }
    return memo[n][m] = cost(arr, n, m) + min(minPathSum(arr, memo, n - 1, m),
                                              minPathSum(arr, memo, n, m - 1));
}
int main()
{
    int arr[3][3] = {
        {10, 15, 20},
        {25, 30, 35},
        {40, 45, 50}};
    int n = 2;
    int m = 2;
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    cout << minPathSum(arr, memo, n, m);
    return 0;
}