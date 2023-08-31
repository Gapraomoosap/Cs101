#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void reverse(Node **head_ref)
{
    Node *prev = NULL;
    Node *current = *head_ref;
    Node *next = *head_ref;
    if (*head_ref == NULL)
    {
        cout << "";
        return;
    }
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void push(Node **head_ref,int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main()
{
    int n, x;
    Node *head = NULL;
    cin>>n;
    for(int i = 0; i< n ;i++)
    {
        cin >> x;
        push(&head,x);
    }
    reverse(&head);
    while (head != NULL)
    {
        cout << head->data << " " << endl;
        head = head->next;
    }
}