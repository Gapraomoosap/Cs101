#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    // Create a new node
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "Error: Must have a previous node." << endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void append(Node **head_ref,int new_data)
{
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node -> data= new_data ;
    new_node -> next =NULL;
    if (*head_ref==NULL){
        *head_ref = new_node;
        return;
    }
    while (last -> next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    
}

int main()
{
    Node* head = NULL;

    push(&head, 1);
    push(&head, 7);
    push(&head, 4);
    append(&head,99);
    Node* temp = head;

    // Search for the node with data = 1
    while (temp != NULL && temp->data != 1)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Node with data 1 not found." << endl;
    }
    else
    {
        insertAfter(temp, 9);
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}
