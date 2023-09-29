#include <iostream>
using namespace std;
class MaxHeap
{

public:
    int index;
    int arr[1000];


    void swap(int i,int value)
    {   
        int temp = arr[i/2];
        cout << "temp : " << temp << endl;
        cout << "arr[i/2] : " << arr[i/2] << endl;
        cout << "arr[i] : " << arr[i] << endl;
        arr[i/2] = value;
        arr[i] = temp;
        // cout << "arr[" << i << "] : " << arr[i] << "      arr[" << i/2 << "] : " << arr[i/2] << endl;
        i = i/2;
        cout << "i = " << i << endl;
        if(i != 1)
        {
            cout << arr[i/2];
            swap(i,arr[i/2]);
        }
    }

    bool check(int value)
    {
        return value < arr[index/2];
    }

    void add()
    {
        int x;
        cin >> x;
        if(index == 1)
        {
            arr[index] = x;
            index++;
        }
        else{
            if(check(x)){
                arr[index] = x;
                index++;
            }
            else{
                cout << "swap" << endl;
                swap(index,x);
                index++;
            }
        }

    }
};

int main()
{
    string x;
    MaxHeap test;
    test.index = 1;
    while (x != "e")
    {
        cin >> x;
        if (x == "a")
        {
            test.add();
        }
    }
    cout << "end";
}