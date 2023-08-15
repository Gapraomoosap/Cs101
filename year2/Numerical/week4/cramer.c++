#include <iostream>
using namespace std;

double calDet(double array[3][4])
{
    double d, u;
    d = array[0][0] * array[1][1] * array[2][2] + array[0][1] * array[1][2] * array[2][0] + array[0][2] * array[1][0] * array[2][1];
    u = -(array[2][0] * array[1][1] * array[0][2]) - (array[2][1] * array[1][2] * array[0][0]) - (array[2][2] * array[1][0] * array[0][1]);
    return d + u;
}

double swap(double array[3][4], int x)
{
    double temp[3][4];
    for(int i = 0 ; i< 3 ;i++)
    {
        for(int j = 0 ;j<3;j++){
            temp[i][j] = array[i][j];
        }
    }
    temp[0][x] = array[0][3];
    temp[1][x] = array[1][3];
    temp[2][x] = array[2][3];
    return calDet(temp);
}

int main()
{
    int i = 0, j = 0;
    double array[3][4] = {{-2, 3, 1, 9}, {3, 4, -5, 0}, {1, -2, 1, -4}};

    double A = calDet(array);
    double A1 = swap(array, 0);
    double A2 = swap(array, 1);
    double A3 = swap(array, 2);
    cout << "X1 = " << A1 / A << endl
         << "X2 = " << A2 / A << endl
         << "X3 = " << A3 / A << endl;
}
