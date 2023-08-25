#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void printlist(Node **head_ref)
{
    Node *temp_node = *head_ref;
    while (temp_node != NULL)
    {
        cout << temp_node->data << " ";
        temp_node = temp_node->next;
    }
    cout << endl;
}


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
    last->next = new_node;
    return;
}
void delPos(Node **head_ref, int pos)
{
    Node *current = *head_ref;
    Node *previous = *head_ref;
    if (*head_ref == NULL)
    {
        cout << "list is empty";
        return;
    }
    else if (pos == 1)
    {
        *head_ref = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}
void reverse(Node **head_ref)
{
    Node *current = *head_ref;
    Node *prev = NULL;
    Node *next = NULL;
    if(*head_ref==NULL){
        return;
    }
    while (current!=NULL ){
        next = current->next;
        current->next = prev;
        prev = current;
        current=next;
    }
    *head_ref = prev;

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
    cout << "before : ";
    printlist(&head);
    delPos(&head, 1);
    reverse(&head);
    cout << "after : ";
    printlist(&head);


}
