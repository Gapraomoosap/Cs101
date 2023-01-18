#include<stdio.h>
#include <math.h>
int main(){
	int a , b ,c;
	scanf("%d %d",&a,&b);
	c = b / a;
	if (b%a != 0)
	{
		c = c+1;
	}
	printf("%d",c);

	return 0;
}