#include <stdio.h>
#include <math.h>

int main() {
    int i, j, k, n, h, w;

    scanf("%d %d", &h, &w);
    
    int a[h][w], s_h, s_w, _max= -9999, cal, range;
    
    for(i=0;i<h;i++) {
        for(j=0;j<w;j++) {
            scanf("%d", &a[i][j]);
        }
       
        if(i != 0) {
            for(k=0; k<w; k++) {
                cal = abs(a[i-1][k] - a[i][k]);
                if(cal <= 10) {
                    range = a[i-1][k] + a[i][k];
                    if(range > _max) {
                        _max = range;
                        s_h = i-1 +1;
                        s_w = k +1;
                    }
                }
            }
        }
    }
    printf("%d %d", s_h, s_w);
}