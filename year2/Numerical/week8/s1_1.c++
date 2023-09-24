#include <iostream>
using namespace std;

double func(int x0, int x1, int x2, double inp)
{
    double Xn[5] = {0, 20000, 40000, 60000, 80000};
    double Y[5] = {9.81, 9.7487, 9.6879, 9.6879, 9.5682};
    double C0 = Y[x0 - 1];
    double C1 = (Y[x1 - 1] - Y[x0 - 1]) / (Xn[x1 - 1] - Xn[x0 - 1]);
    double C2 = (((Y[x2 - 1] - Y[x1 - 1]) / (Xn[x2 - 1] - Xn[x1 - 1])) - C1) / (Xn[x2 - 1] - Xn[x0 - 1]);
    return C0 + C1 * (inp - Xn[x0 - 1]) + C2 * (inp - Xn[x0 - 1]) * (inp - Xn[x1 - 1]);
}

int main()
{
    double x0, x1,x2, xin;
    cout << "Point 1 = ";
    cin >> x0;
    cout << "Point 2 = ";
    cin >> x1;
    cout << "Point 3 = ";
    cin >> x2;
    cout << "Xn = ";
    cin >> xin;
    cout << "Ans = " << func(x0, x1,x2, xin);
}