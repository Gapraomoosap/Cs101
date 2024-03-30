#include <iostream>
using namespace std;
int dp[10][10];
int C(int n, int k)
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= min(i, k); ++j)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[n][k];
}
int main()
{
    cout << C(7, 5) << endl;
    return 0;
}