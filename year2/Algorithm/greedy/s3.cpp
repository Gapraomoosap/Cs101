#include <bits/stdc++.h>
using namespace std;
void bbs(float arr[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j][0] > arr[j + 1][0])
            {
                swap(arr[j][0], arr[j + 1][0]);
                swap(arr[j][1], arr[j + 1][1]);
            }
        }
    }
}
void slove(float arr[][2], int n)
{
    int count = 1;
    int max_count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i][1] - arr[i + 1][0] == 0)
        {
            count++;
            if (count > max_count)
                max_count = count;
        }
        else
        {
            count = 1;
        }
    }
    cout << max_count;
}
int main()
{
    int n;
    cin >> n;
    cout << fixed << setprecision(2);
    float arr[n][2];
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];
    bbs(arr, n); 
    slove(arr, n);
}