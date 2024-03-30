#include <bits/stdc++.h>
using namespace std;
int V[] = {12, 5, 4, 2};
int W[] = {8, 7, 4, 2};
int max_v = -1;
int ans[4];
int K = 18;
void print_sol(int x[], int n)
{
    int w_temp = 0, v_temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            w_temp += W[i];
            v_temp += V[i];
        }
    }
    if (w_temp <= K && v_temp > max_v)
    {
        max_v = v_temp;
        for (int j = 0; j < n; j++)
        {
            ans[j] = x[j];
        }
    }
}
bool check(int x[], int r)
{
    int w_temp = 0;
    for (int i = 0; i < r; i++)
    {
        if (x[i] == 1)
        {
            w_temp += W[i];
        }
    }
    if (w_temp > K)
    {
        return true;
    }
    return false;
}
void Subset1(int x[], int l, int r)
{
    if (l == r)
    {
        if (!check(x, r))
            print_sol(x, r);
    }
    else
    {
        x[l] = 1;
        Subset1(x, l + 1, r);
        x[l] = 0;
        Subset1(x, l + 1, r);
    }
}
int main()
{
    int x[4] = {0, 0, 0, 0};
    Subset1(x, 0, 4);
    cout << "Items: ";
    for (int i = 0; i < 4; i++)
    {
        if (ans[i] == 1)
        {
            cout << W[i] << " ";
        }
    }
    cout << endl
         << "Max value: " << max_v;
    return 0;
}