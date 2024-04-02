#include <iostream>
#include <cmath>
using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int x[],int start,int end,int *count){
	int p,q;
	if(start == end){
		for(int i = 1;i<=end;i++){
			if(x[i]==1){
				p=i;	
			}
			if(x[i]==2){
				q=i;	
			}
		//	cout<<x[i]<<" ";
		}
			if(fabs(q-p)==1){
				(*count)++;
			}
		//cout<<endl;
		return;
	}
	for(int i = start;i<=end;i++){
		swap(&x[start],&x[i]);
		permute(x,start+1,end,count);
		swap(&x[start],&x[i]);
	}
}
int main(){
	int count =0,n;
	cin>>n;
	int x[n+1];
	for(int i=1;i<=n;i++){
		x[i]=i;
	}
	permute(x,1,n,&count);
	cout<<count;
	return 0;
}