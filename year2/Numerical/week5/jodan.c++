#include <iostream>
#include <iomanip>
using namespace std;

void eliminate(double array[3][4], int x)
{
    double temp = array[x - 1][0];
    for (int i = 0; i < 4; i++)
    {
        array[x - 1][i] = array[0][i] - (array[x - 1][i] / temp * array[0][0]);
    }
}
void eliminate2(double array[3][4]){
    double temp = array[2][1];
    for (int i = 1; i < 4; i++)
    {
        array[2][i] = array[1][i] - (array[2][i] / temp * array[1][1]);
    }
}

void Reverse_eliminate(double array[3][4], int x)
{
    double temp = array[x - 1][2];
    for (int i = 0; i < 4; i++)
    {
        array[x - 1][i] = array[2][i] - (array[x - 1][i] / temp * array[2][2]);
    }
}
void Reverse_eliminate2(double array[3][4]){
    double temp = array[0][1];
    for (int i = 0; i < 4; i++)
    {
        array[0][i] = array[1][i] - (array[0][i] / temp * array[1][1]);
        // cout << array[0][i] << " ";
    }
}
int main()
{
    double array[3][4] = {{-2.0, 3.0, 1.0, 9.0}, {3.0, 4.0, -5.0, 0.0}, {1.0, -2.0, 1.0, -4.0}};
    int i, j;
    double X3,X2,X1;
    cout << fixed << setprecision(1);
    eliminate(array, 2);
    eliminate(array, 3);
    eliminate2(array);
    Reverse_eliminate(array,2);
    Reverse_eliminate(array,1);
    Reverse_eliminate2(array);
    X3 =  array[2][3]/array[2][2];
    X2 =  array[1][3]/array[1][1];
    X1 =  array[0][3]/array[0][0];
    cout << "X3 : " << X3 << endl;
    cout << "X2 : " << X2 << endl;
    cout << "X1 : " << X1 << endl;
}