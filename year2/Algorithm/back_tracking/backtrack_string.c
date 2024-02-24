#include <stdio.h>

void backtrack(int n, int k, char x[], int ones, int i)
{
    if (i == n)
    {
        if (ones == k)
        {
            x[n] = '\0';
            printf("%s\n", x);
        }
        return;
    }

    if(ones > k)
        return;
    x[i] = '0';
    backtrack(n,k,x,ones,i+1);

    x[i] = '1';
    backtrack(n,k,x,ones+1,i+1);
}

int main(){
    int N,K;
    scanf("%d %d", &N,&K);
    char x[N+1];
    backtrack(N,K,x,0,0);
    return 0;
}