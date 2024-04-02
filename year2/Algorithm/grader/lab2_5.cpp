#include <iostream>

using namespace std;

int main() {
    int n,i,j,maxcustomers = 0,starthour = 0,endhour = 0,s,e;
    cin>>n;
    int time[24];
    for(i=0;i<=23;i++){
    	time[i]=0;
	}
    for(i=0;i<n;i++) {
        cin>>s>>e;
        for(j=s;j<=e;j++){
        	time[j]++;
        	if(time[j]>maxcustomers){
        		maxcustomers = time[j];
        		starthour = j;
			}
			if(time[j]==maxcustomers){
				endhour = j;
			}
		}	
    }
	cout<<starthour<<" "<<endhour<<" "<<maxcustomers;
    return 0;
}