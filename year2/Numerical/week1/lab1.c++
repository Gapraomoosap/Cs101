#include <iostream>
int main()
{
    using namespace std;
    double ans;
    int array[10];
    double prev_state, curent;
    for (int i = 0; i < 10; i++)
    {
        array[i] = 43.0 * i - 180;
        if (i > 0)
        {
            if (array[i] * array[i-1] < 0 ){
                prev_state = i-1;
                curent = i;
                break;
            }
        }
    }
        
    while (true)
    {
        ans = 43.0 * (prev_state) -180.0;
        if(ans > 0.0001)
        {
            break;
        }
        prev_state += 0.000001;
    }
        cout << prev_state << endl;
    
}