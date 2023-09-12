#include <stdio.h>
#include <math.h>

void func(double X[4], double result[4])
{
    double matrix[4][4] = {{5.0, 2.0, 0.0, 0.0},
                           {2.0, 5.0, 2.0, 0.0},
                           {0.0, 2.0, 5.0, 2.0},
                           {0.0, 0.0, 2.0, 5.0}};
    double Mb[4] = {12.0, 17.0, 14.0, 7.0};

    result[0] = (Mb[0] - X[1] * matrix[0][1] - X[2] * matrix[0][2] - X[3] * matrix[0][3]) / matrix[0][0];
    result[1] = (Mb[1] - X[0] * matrix[1][0] - X[2] * matrix[1][2] - X[3] * matrix[1][3]) / matrix[1][1];
    result[2] = (Mb[2] - X[0] * matrix[2][0] - X[1] * matrix[2][1] - X[3] * matrix[2][3]) / matrix[2][2];
    result[3] = (Mb[3] - X[0] * matrix[3][0] - X[1] * matrix[3][1] - X[2] * matrix[3][2]) / matrix[3][3];
}

int main()
{
    double X[4] = {0.0, 0.0, 0.0, 0.0};
    double result[4];

    double Error = 0.01;
    int i = 0;

    func(X, result);

    while ((fabs(result[0] - X[0] / result[0]) * 100 >= Error) &&
           (fabs(result[1] - X[1] / result[1]) * 100 >= Error) &&
           (fabs(result[2] - X[2] / result[2]) * 100 >= Error))
    {
        printf("X[0] Error: %lf\n", (fabs(result[0] - X[0] / result[0]) ));
        printf("X[1] Error: %lf\n", (fabs(result[1] - X[1] / result[1]) ));
        printf("X[2] Error: %lf\n", (fabs(result[2] - X[2] / result[2]) ));
        for (int j = 0; j < 4; j++)
        {
            X[j] = result[j];
        }
        func(X, result);
        printf("Iteration %d:\n", i + 1);
        printf("X[0]: %lf\n", result[0]);
        printf("X[1]: %lf\n", result[1]);
        printf("X[2]: %lf\n", result[2]);
        printf("X[3]: %lf\n", result[3]);

       

        i++;
    }

    return 0;
}
