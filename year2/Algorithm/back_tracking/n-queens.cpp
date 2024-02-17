#include <stdio.h>
#include <cmath>

int n = 4, x[4];

bool check(int k, int row)
{
    for (int i = 0; i < k; i++)
    {
        if (x[i] == row || abs(i - k) == abs(x[i] - row))
            return false;
    }
    return true;
}

void n_queen(int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", x[i]);
        }
        printf("\n");
    }
    else
    {
        for (int row = 0; row < n; row++)
        {
            if (check(k, row))
            {
                x[k] = row;
                n_queen(k + 1);
            }
        }
    }
}

int main()
{
    n_queen(0);
    return 0;
}
