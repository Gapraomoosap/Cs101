#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, i, j, k,ans[100],loop;
    scanf("%d", &n);
    loop = n;
    for(i = 0; i < n; i++) {
        scanf("%d", &m);
        int array[m],max=0,count=0;
        for(j = 0; j < m; j++) {
            scanf("%d", &array[j]);
        }
        for(k = m-1;k>=0;k--){
            if(array[k]>max){
                max = array[k];
                count++;
            }
        }
        ans[i] = count ;
    }
    
    for(i = 0 ; i < loop ; i++ )
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
