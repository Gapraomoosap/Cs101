#include<iostream>
#include<string>
using namespace std;
class Stack{
	public:
		int arr[100];
		int top =- 1;
		void push(int item){
			arr[++top]=item;
		}
		int pop(){
			return arr[top--];
		}
		bool empty(){
			if(top <= -1)
			return true;
			else
			return false;
		}
		bool full(){
			if(top >= 10)
			return true;
			else
			return false;
		}
};

int main(){
	Stack s;
	string x;
	int flag=0;
	cin>>x;
	
	for(int i=0;i<x.length();i++){
		if(x[i]=='(')
		s.push(x[i]);
		else if(x[i]==')'){
			if(s.empty()==true){
				cout<<"Error"<<endl;
				flag=1;
				break;
			}
			else
			s.pop();
		}
	}
	
	if(flag!=1){
		if(s.empty()==true)
		cout<<"Pass"<<endl;
		else
		cout<<"Error"<<endl;
	}
	
	return 0;
}
