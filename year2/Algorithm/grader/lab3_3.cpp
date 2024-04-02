#include <iostream>

using namespace std;

void swap(int *i,int *j){
	int k = *i;
	*i = *j;
	*j = k;
}
int partition(int a[], int l, int r,int k) {
    int pivot, i, j, t;
pivot = a[r]; // first item always as the pivot
i = l;
j = r + 1;
while(1)
{ do { ++i;

}while(a[i] <= pivot);
do { --j;
}while(a[j] > pivot);

if(i >= j)
break;
swap(&a[i], &a[j]);

}
swap(&a[l], &a[j]);
    if(k==j+1){
    	return j;
	}
	else if(k<=j){
		partition(a,0,j,k);
	}else{
		partition(a,j+1,r,k-j+1);
	}
}

int main(){
	int i,n,k,count;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<partition(arr,0,n-1,k);
	return 0;
}