#include <iostream>
using namespace std;
double Fx(int n, double l[], double Y[])
{
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + (l[i] * Y[i]);
    }
    return ans;
}
double CalL(double X[], double Xn, int n,int r)
{
    double ans = 1;
    for (int i = 0; i < r; i++)
    {
        if (i == n);
        else
        {
            ans = ans * (X[i] - Xn) / (X[i] - X[n]);
        }
    }
    return ans;
}
int main()
{
    double X[] = {0,40000, 80000};
    double Y[] = {9.81, 9.6879,9.5682};
    int n = 3;
    double L[n];
    double Xn = 42235;
    for (int i = 0; i < n; i++)
    {
        L[i] = CalL(X, Xn, i,n);
    }
    cout << Fx(n, L, Y);
}