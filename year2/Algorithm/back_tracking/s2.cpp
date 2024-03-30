#include <bits/stdc++.h>
using namespace std;
int n = 4, x[4];
bool isSafe(int k, int row)
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == row || abs(j - k) == abs(x[j] - row))
        {
            return false;
        }
    }
    return true;
}
void n_queens(int k)
{
    if (k == n)
    {
        for (int i = 0; i < k; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    else
    {
        for (int row = 0; row < n; row++)
        {
            if (isSafe(k, row))
            {
                x[k] = row;
                n_queens(k + 1);
            }
        }
    }
}
int main()
{
    n_queens(0);
    return 0;
}