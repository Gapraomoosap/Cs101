#include <bits/stdc++.h>
using namespace std;
void sol(int a[][2], int n, int xa, int xb)
{
    vector<vector<int>> ans;
    int curX = xa + 1;
    int i = 0;
    while (i < n && curX < xb)
    {
        int maxR = -1;
        vector<int> temp;
        while (i < n && a[i][0] <= curX)
        {
            if (curX - 1 == a[i][0])
            {
                if (a[i][1] > maxR)
                {
                    maxR = a[i][1];
                    temp.clear();
                    temp.push_back(a[i][0]);
                    temp.push_back(a[i][1]);
                }
            }
            i++;
        }
        if (maxR == -1)
        {
            cout << -1;
            return;
        }
        ans.push_back(temp);
        curX = maxR;
    }
    if (curX < xb)
    {
        cout << -1;
        return;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i][0] << " " << ans[i][1] << endl;
}
int main()
{
    int n;
    cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];
    int xa, xb;
    cin >> xa >> xb;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j][0] > a[j + 1][0])
            {
                swap(a[j][0], a[j + 1][0]);
                swap(a[j][1], a[j + 1][1]);
            }
        }
    }
    sol(a, n, xa, xb);
    return 0;
}