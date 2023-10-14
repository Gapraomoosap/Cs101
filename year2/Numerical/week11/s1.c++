#include <iostream>
#include <cmath>
#include <numeric>
#include <math.h>
using namespace std;

double func(double a0, double a1, double x)
{
    return a0 + a1 * x;
}

double determinant(double matrix[10][10], int n)
{
    double det = 0;
    double submatrix[10][10];
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}

double swap(double array[10][10], int x)
{
    double temp[10][10];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp[i][j] = array[i][j];
        }
    }
    temp[0][x] = array[0][3];
    temp[1][x] = array[1][3];
    temp[2][x] = array[2][3];
    return determinant(temp, 3);
}

double square(double x[], int size, int power)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + pow(x[i], power);
    }
    return sum;
}

double XandY(double x[], double y[], int powx, int powy, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + (pow(x[i], powx) * pow(y[i], powy));
    }
    return sum;
}
int main()
{
    double x[] = {10, 15, 20, 30, 40, 50, 60, 70, 80};
    double y[] = {5, 9, 15, 18, 22, 30, 35, 38, 43};
    int size = sizeof(x) / sizeof(x[0]);
    double sum_x2, sum_x[5], sum_y[3];
    int poly = 3;
    double mtx[10][10];
    for (int i = 1; i <= 4; i++)
    {
        sum_x[i] = square(x, size, i);
    }

    for (int i = 0; i < 3; i++)
    {
        sum_y[i] = XandY(x, y, i, 1, size);
    }

    for (int i = 0; i < poly; i++)
    {
        for (int j = 0; j < poly + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                mtx[0][0] = size;
            }
            else if (j == 3)
            {
                mtx[i][j] = sum_y[i];
            }
            else
            {
                mtx[i][j] = sum_x[i + j];
            }
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
    double A = determinant(mtx, 3);
    double a1 = swap(mtx, 0);
    double a2 = swap(mtx, 1);
    double a3 = swap(mtx, 2);
    cout << "a0 = " << a1 / A << endl
         << "a1 = " << a2 / A << endl
         << "a2 = " << a3 / A << endl;

    // cout<<"Determinant of the matrix is "<< determinant(mtx,2);
}
