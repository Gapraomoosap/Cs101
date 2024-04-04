#include <bits/stdc++.h>
using namespace std;

long long pow(int a, int n){
	int temp;
	if(n == 1){
		return a;
	}
	temp = pow(a, n/2);
	if(n%2 == 0){
		return temp * temp;
	}
	else{
		return a * temp * temp;
	}
}

int main(){
	int a, n;
	cin>>a>>n;
	
	if(n % 2 != 0 && a % 2 != 0) cout<<pow(a, n)<<" "<<floor(n/2.0); // test case 2 (n is odd, a is odd)
    else if (n % 2 != 0 && a % 2 == 0) cout<<pow(a, n)<<" "<<ceil(n/2.0); // test case 3 (n is odd, a is even)
    else cout<<pow(a, n)<<" "<<floor(n/2.0); // test case 1 (n is even, a is even)
	
	return 0;
}