#include<iostream>
using namespace std;

int main()
{
    double a[4][4] = {{5,2,0,0},{2,5,2,0},{0,2,5,2},{0,0,2,5}};
    double b[4] = {12,17,14,7};
    double x[4],ans[4];
    for(int i=0;i<4;i++)
    {
        double sum = 0.0;
        for(int j=i+1;j<4;j++)
        {
            sum += a[i][j]*x[j];
            ans[i] = (b[i]-sum)/a[i][i];
        }
        cout << ans[i] <<endl;
    }
}