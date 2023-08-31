#include <iostream>
#include <stack>
using namespace std;

void printstack(stack<int> stack)
{
    while(!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
}

int main()
{
    stack<int> numbersStack;
    
    numbersStack.push(1);
    numbersStack.push(2);
    numbersStack.push(3);
    if (numbersStack.empty())
        cout << "The Stack is empty" << endl;
    else
        cout << "The Stack isn't Empty" << endl;
    
    cout << "Stack size is " << numbersStack.size()<<endl;
    printstack(numbersStack);
}