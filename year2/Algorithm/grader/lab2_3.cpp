#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int i,j,n,k,a,difference=999,sum,x1,x2;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			sum=0;
			sum=arr[i]+arr[j];
			if(sum == k){
				if(fabs(arr[i]-arr[j])<difference){
					difference = fabs(arr[i]-arr[j]);
					x1 = arr[i];
					x2 = arr[j];
				}
			}
		}
	}
	if(x1>x2){
		int x = x1;
		x1 = x2;
		x2 = x;
	}
	
	cout<<x1<<" "<<x2;
	return 0;
}