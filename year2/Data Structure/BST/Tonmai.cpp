#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

struct Node *Newnode(int data)
{
    struct Node *newnode = new Node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int height(Node *node);

struct Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        return Newnode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << ",";
    Inorder(root->right);
}

void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << ",";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        cout << "|";
    }
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << ",";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << ",";
}
Node *deleteNode(Node *root, int k)
{

    if (root == NULL)
        return root;

    if (root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }
    if (root->left == NULL)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }
    else
    {
        Node *succParent = root;

        Node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->data = succ->data;
        delete succ;
        return root;
    }
}

int main()
{
    Node *root = NULL;
    string x;
    int n_data;
    while (x != "x")
    {
        cin >> x;
        if (x == "a")
        {
            cin >> n_data;
            root = Insert(root, n_data);
        }
        else if (x == "d")
        {
            cin >> n_data;
            root = deleteNode(root, n_data);
        }
        else if (x == "b")
        {
            printLevelOrder(root);
            cout << endl;
        }
        else if (x == "i")
        {
            Inorder(root);
            cout << endl;
        }
        else if (x == "p")
        {
            printPreorder(root);
            cout << endl;
        }
        else if (x == "t")
        {
            printPostorder(root);
            cout << endl;
        }
    }
}
