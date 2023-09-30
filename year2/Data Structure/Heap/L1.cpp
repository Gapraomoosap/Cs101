#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{

public:
    int index;
    int arr[1000];
    int max_heap;

    void Delete()
    {
        int deletedValue = arr[1];
        index--;
        arr[1] = arr[index];
        D_swap(1);
        cout << deletedValue << endl;
    }

    void D_swap(int i)
    {
        int right = i * 2 + 1;
        int left = i * 2;
        int track = i;
        if (arr[left] >= arr[right] && arr[track] < arr[left])
        {
            swap(arr[left], arr[track]);
            track = track * 2;
        }
        else if (arr[right] > arr[left] && arr[track] < arr[right])
        {
            swap(arr[right], arr[track]);
            track = track * 2 + 1;
        }
        else if (arr[left] > arr[track])
        {
            cout << "in func";
            swap(arr[left], arr[track]);
            return;
        }
        if (track*2  < index - 1)
        {
            cout <<"track  = " << track *2<<endl << " index -1 = " << index - 1 << endl;
            D_swap(track);
        }
    }

    void print()
    {
        for (int i = 1; i < index; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }

    void swap_value(int i, int value)
    {
        int temp = arr[i / 2];
        int tpm_i;
        arr[i / 2] = value;
        arr[i] = temp;
        tpm_i = i / 2;
        if (tpm_i != 1 && (arr[tpm_i]) > arr[tpm_i / 2])
        {
            swap_value(tpm_i, arr[i / 2]);
        }
    }

    bool check(int value)
    {
        return value < arr[index / 2];
    }

    void add()
    {
        int x;
        cin >> x;
        if (index == 1)
        {
            arr[index] = x;
            index++;
        }
        else
        {
            if (check(x))
            {
                arr[index] = x;
                index++;
            }
            else
            {
                // cout << "swap_value" << endl;
                swap_value(index, x);
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
        else if (x == "p")
        {
            test.print();
        }
        else if (x == "d")
        {
            test.Delete();
        }
    }
    cout << "end";
}
