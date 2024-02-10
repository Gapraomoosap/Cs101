#include <iostream>
using namespace std;

    int main()
{
    int n = 0, x = 0, a = 0;
    cin >> n;
    cin >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[i] = a;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i == j)
                continue;
            if (arr[i] + arr[j] == x)
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "-1";
}