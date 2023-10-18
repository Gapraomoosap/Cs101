#include <iostream>
#include <cmath>
using namespace std;

double func(double X[], int n, int size)
{
    double sum = 0;
    for (int i = size; i >= 0; i--)
    {
        sum = sum + (X[i] * pow(n, i));
    }
    return sum;
}

double Integration(double X[], int n1, int n2, int size)
{
    double sum1 = 0, sum2 = 0;
    for (int i = size; i >= 0; i--)
    {
        sum1 = sum1 + ((X[i] * pow(n1, i + 1)) / (i + 1));
        sum2 = sum2 + ((X[i] * pow(n2, i + 1)) / (i + 1));
    }
    return sum1 - sum2;
}



int main()
{
    int max_n;
    int Xp, Xd, I;
    double Fx[2];
    cout << "Max degree : ";
    cin >> max_n;
    double X[max_n];
    for (int i = max_n; i >= 0; i--)
    {
        cout << "X^" << i << " : ";
        cin >> X[i];
    }
    cout << "Top : ";
    cin >> Xp;
    cout << "Down : ";
    cin >> Xd;
    Fx[0] = func(X, Xp, max_n);
    Fx[1] = func(X, Xd, max_n);
    I = (((Xp - Xd) / 2) * (Fx[0] + Fx[1]));
    double Inte = Integration(X, Xp, Xd, max_n);
    cout << "I : " << I << endl;
    cout << "Integration : " << Inte << endl;
    cout << "Error : " << (I-Inte)/Inte*100 <<"%";
}