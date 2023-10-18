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

void Xn(int n, double Xn[], int Xp, int Xd) {
    double h = (Xp - Xd) / n;
    for (int i = 0; i < n + 1; i++) {
        Xn[i] = Xd + (i * h);
    }
}

double I_func(double Fx[],double h,int n)
{
    double sum = 0;
    for(int i =0;i<=n;i++)
    {
        if(i == 0 || i == n)
        {
            sum = sum + Fx[i];
        }
        else{
            sum = sum + (2*Fx[i]);
        }
    }
    return sum * (h / 2);
}


int main()
{
    int max_n;
    int Xp, Xd,N;
    double I,Inte;
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
    cout << "N : ";
    cin >> N;
    double Xi[N+1],Fx[N+1],h=(Xp-Xd)/N;
    Xn(N,Xi,Xp,Xd);
    for(int i =0;i<N+1;i++)
    {
        Fx[i] = func(X,Xi[i],max_n);
        cout << Fx[i] << endl;
    }
    I = I_func(Fx,h,N);
    Inte = Integration(X, Xp, Xd, max_n);
    cout << "I : " << I<<endl;
    cout << "Integration : " << Inte << endl;
    cout << "Error : " << (I-Inte)/Inte*100 <<"%";
}