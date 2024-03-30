#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i][0] << " " << arr[i][1] << endl;
    }
    cout << endl;
}
void slove(int a[][2], int n)
{
    int min = 99999;
    int sum, sum1, sum2;
    for (int i = n; i > 0; i--)
    {
        sum = 0;
        sum1 = 0;
        sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            sum1 += a[j][0];
            sum2 += a[j][1];
        }
        sum = abs(sum2 - sum1);
        if (sum == 0)
        {
            cout << 0;
            return;
        }
        if (sum < min)
        {
            min = sum;
        }
        swap(a[i][0], a[i][1]);
    }
    cout << min;
}
int main()
{
    int n;
    cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];
    slove(a, n);
    return 0;
}