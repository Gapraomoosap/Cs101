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
	cin>>x;
	for(int i=0;i<x.length();i++){
		s.push(x[i]);
	}
	for(int i=0;i<x.length();i++){
		cout<<(char)s.pop();
	}
	return 0;	 
}
