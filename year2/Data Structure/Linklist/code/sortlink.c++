#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void printlist(Node **head_ref)
{
    Node *temp_node = *head_ref;
    cout<<endl<<"list : ";
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
void sort(Node **head_ref)
{
    Node *next_node = *head_ref;
    Node *current = *head_ref;
    if (*head_ref == NULL)
    {
        return;
    }
    while (next_node->next != NULL && current->next != NULL)
    {
        next_node = next_node->next;
        if (current->data > next_node->data)
        {
            int temp = current->data;
            current->data = next_node->data;
            next_node->data = temp;
        }
    }
    *head_ref = current;
}

int main()
{
    Node *head = new Node();
    head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    cout << "before  ";
    printlist(&head);
    cout << endl <<"after ";
    // sort(&head);
   
    printlist(&head);

}