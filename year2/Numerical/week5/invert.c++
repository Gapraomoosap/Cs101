#include <iostream>
#include <iomanip>
using namespace std;

void eliminate(double array[3][6], int x)
{
    double temp = array[x - 1][0];
    for (int i = 0; i < 6; i++)
    {
        array[x - 1][i] = array[0][i] - (array[x - 1][i] / temp * array[0][0]);
    }
}

void eliminate2(double array[3][6])
{
    double temp = array[2][1];
    for (int i = 1; i < 6; i++)
    {
        array[2][i] = array[1][i] - (array[2][i] / temp * array[1][1]);
    }
}

void Reverse_eliminate(double array[3][6], int x)
{
    double temp = array[x - 1][2];
    for (int i = 0; i < 6; i++)
    {
        array[x - 1][i] = array[2][i] - (array[x - 1][i] / temp * array[2][2]);
    }
}
void Reverse_eliminate2(double array[3][6])
{
    double temp = array[0][1];
    for (int i = 0; i < 6; i++)
    {
        array[0][i] = array[1][i] - (array[0][i] / temp * array[1][1]);
        // cout << array[0][i] << " ";
    }
}
void Set1(double array[3][6])
{
    for (int i = 0; i < 3; i++)
    {
        double temp = array[i][i];
        for (int j = 0; j < 6; j++)
        {
            array[i][j] = array[i][j] / temp;
        }
    }
}
void solution(double array[3][6], double ans[3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << " X" << i + 1 << " : " << array[i][3] * ans[0] + array[i][4] * ans[1] + array[i][5] * ans[2] << endl;
    }
}
int main()
{
    double array[3][6] = {{-2.0, 3.0, 1.0, 1.0, 0, 0}, {3.0, 4.0, -5.0, 0.0, 1.0, 0.0}, {1.0, -2.0, 1.0, 0.0, 0.0, 1.0}};
    double ans_arr[3] = {9, 0, -4};
    int i, j;
    double X3, X2, X1;
    cout << fixed << setprecision(1);
    eliminate(array, 2);
    eliminate(array, 3);
    eliminate2(array);
    Reverse_eliminate(array, 2);
    Reverse_eliminate(array, 1);
    Reverse_eliminate2(array);
    Set1(array);
    solution(array, ans_arr);
}