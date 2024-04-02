#include <iostream>

using namespace std;

int target(int *A,int k,int l,int r){
	if(l==r){
		if(A[l]==k){
			return 1;
		}else{
			return 0;
		}
	}
	
	int m = (l+r)/2;
	int m1 = target(A,k,l,m);
	int m2 = target(A,k,m+1,r);
	
	return m1+m2;
}

int main(){
	int i,n,k,count;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	count = target(arr,k,0,n-1);
	if(count>0){
		cout<<count;
	}
	else{
		cout<<-1;
	}
	return 0;
}