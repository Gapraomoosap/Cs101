#include<iostream>
#include<string>
using namespace std;
class Stack{
	public:
		int arr[100];
		int top=-1;
		int i;
		void push(int item){
			arr[++top]=item;
		}
		int pop(){
			return arr[top--];
		}
		int showtop(){
			return arr[top];
		}
		int count(){
			return top+1;
		}
		int showall(){
			for(i=0;i<top+1;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			
		}
};
int main(){
	Stack s;
	int n;
	char x;
	while(x!='X'){
		cin>>x;
		if(x=='U'){
			cin>>n;
			s.push(n);
		}
		if(x=='O'){
			cout<<s.pop()<<endl;
		}
		if(x=='T'){
			cout<<s.showtop()<<endl;
		}
		if(x=='P'){
			s.showall();
		}
		if(x=='N'){
			cout<<s.count()<<endl;
		}
	}
	return 0;
}
