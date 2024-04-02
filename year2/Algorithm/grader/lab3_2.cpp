#include <iostream>

using namespace std;

int powA(int n,int k,int *count){
	if(k==0){
		(*count)++;
		return 1;
		
	}
	if(k==1){
		(*count)++;
		return n;
	}
	if(k%2==0){
		(*count)++;
		return powA(n*n,k/2,count);
		
	}else{
		(*count)++;
		return powA(n*n,k/2,count)*n;
	}
}

int main(){
	int i,n,k,count=0;
	cin>>n>>k;
	cout<<powA(n,k,&count)<<" ";
	cout<<count;
	return 0;
}