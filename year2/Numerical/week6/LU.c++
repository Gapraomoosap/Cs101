#include <iostream>
#include <iomanip>
using namespace std;
void LU(double array[10][10], double L[10][10], double U[10][10], int n)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j > i)
                L[j][i] = 0;
            else
            {
                L[i][j] = array[i][j];
            }
        }
    }
}
int main()
{
    int n = 3, i = 0, j = 0;
    double matrix[10][10] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, L[10][10], U[10][10];
    LU(matrix, L, U, 3);
    cout << "L Decomposition is as follows..." << endl;
    cout << fixed << setprecision(1);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}