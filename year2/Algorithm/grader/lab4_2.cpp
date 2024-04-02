#include <iostream>
using namespace std;
int c = 0;
void print_sol(int x[],int n,int arr[],int k){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(x[i]==1){
			sum += arr[i-1];
		}
	}	if(sum==k){		
		if(c==0){
			c=1;
		}
		else{
			cout<<endl;
		}
		for(int i=1;i<=n;i++){
			if(x[i]==1){
				cout<<arr[i-1]<<" ";
			}
		}
	}
}

void subset1(int x[],int l,int r,int arr[],int k,int sum){
	if(l==r){
		print_sol(x,r,arr,k);
		return;
	}
	if(sum>k){
		return;
	}
	x[l+1]=1;
	sum += arr[l];
	subset1(x,l+1,r,arr,k,sum);
	x[l+1]=0;
	sum -=arr[l];
	subset1(x,l+1,r,arr,k,sum);
}

int main(){
	int n,k;
	cin>>n>>k;
	int x[n+1],arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	subset1(x,0,n,arr,k,0);
	return 0;
}