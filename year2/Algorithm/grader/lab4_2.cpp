#include <iostream>
using namespace std;
void print_sol(int x[],int n,int arr[],int k,int *c){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(x[i]==1){
			sum += arr[i-1];
		}
	}	if(sum==k){
			/*for(int j=1;j<=n;j++){
				if(x[j]==1){
					cout<<" "<<arr[j-1];
				}
			}
			cout<<endl;*/
		if(*c==0){
			*c=1;
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

void subset1(int x[],int l,int r,int arr[],int k,int *c){
	if(l==r){
		print_sol(x,r,arr,k,c);
	}else{
		x[l+1]=1;
		subset1(x,l+1,r,arr,k,c);
		x[l+1]=0;
		subset1(x,l+1,r,arr,k,c);
	}
}

int main(){
	int n,k,c=0;
	cin>>n>>k;
	int x[n+1],arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	subset1(x,0,n,arr,k,&c);
	return 0;
}
