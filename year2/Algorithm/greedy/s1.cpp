#include <bits/stdc++.h>
using namespace std;
void knapsack(int n, int W, int a[][2])
{
    float t[n]; 
    int t_i[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = a[i][1] / (a[i][0] + 0.0);
        t_i[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (t[j] < t[j + 1])
            {
                swap(t[j], t[j + 1]);
                swap(t_i[j], t_i[j + 1]);
            }
        }
    }
    int w_cal = 0;
    float p = 0;
    float ans[n] = {0};
    for (int i = 0; i < n; i++)
    {
        w_cal += a[t_i[i]][0];
        if (w_cal > W)
        {
            w_cal -= a[t_i[i]][0];
            int temp = a[t_i[i]][0] * ((W - w_cal) / a[t_i[i]][0]);
            w_cal += temp;
            ans[t_i[i]] = ((W - w_cal) / (a[t_i[i]][0] + 0.0));
            int temp_p = a[t_i[i]][1] * ((W - w_cal) / a[t_i[i]][1]);
            p += ans[t_i[i]] * a[t_i[i]][1];
            break;
        }
        ans[t_i[i]] = 1;
        p += a[t_i[i]][1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << ans[i] << " ";
    }
    cout << endl
         << p;
}
int main()
{
    int n, W;
    cin >> n >> W;
    int a[n][2];
    for (int i = 0; i < n; i++)
        cin >> a[i][0];
    for (int j = 0; j < n; j++)
        cin >> a[j][1];
    knapsack(n, W, a);
    return 0;
}