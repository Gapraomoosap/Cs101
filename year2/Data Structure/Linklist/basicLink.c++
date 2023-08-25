#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void insertAfter(Node *prev_node, int data)
{
    Node *new_node = new Node();
    if (prev_node == NULL)
    {
        cout << "Previous node must not NULL";
    }
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node **head_ref, int data)
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return; 
    }
    while (last->next != NULL) 
    {
        last = last->next;
        // cout << last->data << " " ;
    }
    last->next=new_node;
    return;
}

int main()
{
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 9);
    push(&head, 3);
    append(&head, 100);
    insertAfter(head->next, 5);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
