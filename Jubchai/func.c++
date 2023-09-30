#include <iostream>
using namespace std;
void swap(int L[])
{
    L[0] += 5 ;
    L[1] += 10 ;
    L[2] += 15 ;
}

int main()
{
    int L[]={0,0,0};
    int K[]={5,10,20};
    for (int i=0 ; i<5 ;i++)
    {
        swap(L);
        cout << i+1 << ") "<< endl;
        for (int j=0 ; j<3 ;j++)
        {
            cout << "L["<<j<<"] = "<< L[j] << endl;
        }
    }
}