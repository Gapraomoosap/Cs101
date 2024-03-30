#include <bits/stdc++.h>
using namespace std;
int count(vector<int> &coins, int n, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] += dp[i - 1][j];
            if ((j - coins[i - 1]) >= 0)
            {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[n][target];
}
int main()
{
    vector<int> coins = {1, 4, 5, 10};
    int target = 8;
    cout << count(coins, coins.size(), target) << endl;
    return 0;
}
