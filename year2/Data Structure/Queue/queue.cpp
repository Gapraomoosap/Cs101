#include<iostream>
using namespace std;
class Queue{
	public:
		int arr[5];
		int head = 0;
		int tail = -1;
		int queuesize = 0;
		void enqueue(int data){
			if(tail >= 4){
				cout<<"Full"<<endl;
			}
			else if(tail>4){
				tail = 0;
				queuesize++;
				arr[tail] = data;
			}
			else{
				tail++;
				queuesize++;
				arr[tail] = data; 
			}	
		}
		int dequeue(){
			if(tail<head){
				cout <<"Empty"<<endl;
				return -1;
			}
			else if(head>=4){
				int x = arr[head];
				head = 0 ;
				queuesize--;
				return x;
			}
			else{
				int x = arr[head];
				head++;
				queuesize--;
				return x;
			}
		}
		void showall(){
			for(int i=head;i<=tail;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		void n(){
			cout<<queuesize<<endl;
		}
		void s(){
			if(tail== -1){
				cout<<"";
			}
			else{
				cout<<arr[head]<<" "<<arr[tail]<<endl;
			}
		}
};
int main(){
	Queue q;
	int n;
	char x;
	while(x!='x'){
		cin>>x;
		if(x=='e'){
			cin>>n;
			q.enqueue(n);
		}
		if(x=='d'){
			cout<<q.dequeue()<<endl;
		}
		if(x=='p'){
			q.showall();
		}
		if(x=='n'){
			q.n();
		}
		if(x=='s'){
			q.s();
		}
	}
}
