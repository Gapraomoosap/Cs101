#include <stdio.h>
int main()
{
    int i, j, k; scanf("%d %d %d",&i,&j,&k);
    char s[10];  scanf("%s",&s);
    int a = 0;
    if (i < j && i < k)
    {
        a = i;
    }
    else if (j < i && j < k)
    {
        a = j;
    }
    else
    {
        a = k;
    }
    int c = c;
    if (i > j && i > k)
    {
        c = i;
    }
    else if (j > i && j > k)
    {
        c = j;
    }
    else
    {
        c = k;
    }
    int b = 0;
    if ((j < i && i < k) || (k < i && i < j))
    {
        b = i;
    }
    else if ((i < j && j < k) || (k < j && j < i))
    {
        b = j;
    }
    else
    {
        b = k;
    }

    if(s[0] == 'A')         {printf("%d ",a);}
    else if (s[0]== 'B')    {printf("%d ",b);}
    else                    {printf("%d ",c);}

    if(s[1] == 'A')         {printf("%d ",a);}
    else if (s[1]== 'B')    {printf("%d ",b);}
    else                    {printf("%d ",c);}

    if(s[2] == 'A')         {printf("%d ",a);}
    else if (s[2]== 'B')    {printf("%d ",b);}
    else                    {printf("%d ",c);}

    return 0;
}