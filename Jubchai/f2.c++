#include <iostream>
using namespace std;

void func(int L[], int K[])
{
    for (int i = 0; i < 8; i++)
    {
        L[i] += K[7 - i];
    }
}
int main()
{
    int L[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int K[] = {5, 10, 20, 99, 78, 55, 4, 65};
    int sum, count = 1;
    do
    {
        sum = 0;
        cout << count << endl;
        func(L, K);
        for (int i = 0; i < 8; i++)
        {
            cout << "L[" << i << "] = " << L[i] << endl;
            sum += L[i];
            // cout <<"SUM : "<<sum<<endl;
        }
        count++;
    } while (sum < 1000);
}