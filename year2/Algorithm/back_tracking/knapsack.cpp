#include <iostream>
using namespace std;
int W[] = {12, 5, 4, 2};
int V[] = {8, 7, 4, 2};
int max_v = -1;
int ans[4];
int K = 18;

void print_sol(int x[], int n)
{
    int w_temp = 0, v_temp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            w_temp += W[i - 1];
            v_temp += V[i - 1];
        }
    }
    if (w_temp <= K && v_temp > max_v)
    {
        max_v = v_temp;
        for (int j = 1; j <= n; j++)
            ans[j] = x[j];
    }
}

void Subset1(int x[], int l, int r)
{
    if (l == r)
    {
        print_sol(x, r);
    }
    else{
        x[l+1] = 1;
        Subset1(x,l+1,r);
        x[l+1] = 0;
        Subset1(x,l+1,r);
    }
}

int main(){
    int n =4;
    int x[n+1];
    Subset1(x,0,n);

    return 0;
}