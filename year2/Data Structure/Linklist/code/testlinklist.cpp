#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
void push(Node** head_ref,int new_data){
	Node* new_node = new Node();
	new_node -> data = new_data;
	new_node -> next = *head_ref;
	*head_ref = new_node;
}
void reverse(Node** head,int new_data){
	Node *tmp = *head,*new_head = NULL;
	Node *next_tmp = NULL;
	while(tmp != NULL){
		next_tmp = tmp -> next;
		tmp -> next = new_head;
		new_head = tmp;
		tmp = next_tmp;
	}
	*head = new_head;
}
int main(){
	int n,data;
	cout << "n :";
	cin >> n;
	Node *head = NULL;
		cout << "data :"; 
	for(int i=0;i<n;i++){
		cin >> data;
		push(&head,data);
	}
		reverse(&head,data);
	while(head != NULL ){
		cout << head -> data << "\n";
		head = head -> next;
	}
}
