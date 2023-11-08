#include <iostream>
using namespace std;

class Min
{
public:
    int index;
    int arr[1000];

    void Check(int idx)
    {
        if (arr[idx] > arr[idx / 2])
        {
            return;
        }
        else
        {
            int ptx = arr[idx / 2];
            arr[idx / 2] = arr[idx];
            arr[idx] = ptx;
        }
        idx = idx / 2;
        
        if (idx == 1)
        {
  
            return;
        }
        else
        {
            Check(idx);
        }
    }

    void Insert(int x)
    {
        arr[index] = x;
        int idx = index;
        Check(idx);
    }

    void add()
    {
        int value;
        cin >> value;
        if (index == 1)
        {
            arr[index] = value;
            index++;
        }
        else
        {
            Insert(value);
            index++;
        }
    }
    void print(){
        for(int i = 1;i<index;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }
};

int main()
{
    string x;
    Min Minheap;
    Minheap.index = 1;
    while (x != "e")
    {
        cin >> x;
        if (x == "a")
        {
            Minheap.add();
        }
        else if(x == "p")
        {
            Minheap.print();
        }

    }
}