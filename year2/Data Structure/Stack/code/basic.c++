#include<iostream>
class Node {
    public:
        char val;
        Node* next;
};

class Stack {
    private:
        Node *head = NULL;
    public:
        void push(char val) {
            // Insert First
            Node *new_node = new Node();
            new_node->val = val;
            new_node->next = head;

            head = new_node;
        }
        bool empty() {
            return head == NULL;
        }
        void pop() {
            // Delete First
            Node *tmp = head;
            head = head->next;

            delete tmp;
        }
        char top()  {
            return head->val;
        }
};
int main ()
{
    
}