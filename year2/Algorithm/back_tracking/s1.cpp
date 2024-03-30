#include <bits/stdc++.h>
using namespace std;
void permute(int x[], int start, int end)
{
    if (start == end)
    {
        int flag = 0;
        for (int j = 1; j < end; j++)
        {
            for (int p = 0; p < j; p++)
            {
                if (abs(p - j) == abs(x[p] - x[j]) || (x[j] == x[p]))
                    flag = 1;
            }
        }
        if (flag == 0)
        {
            for (int i = 1; i <= end; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(x[start], x[i]);
        permute(x, start + 1, end);
        swap(x[start], x[i]);
    }
}
int main()
{
    int n = 4;
    int x[] = {-1, 1, 2, 3, 4};
    permute(x, 1, n);
    return 0;
}