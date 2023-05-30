#include <stdio.h>

int main()
{
    int secret = 0;
    scanf("%d", &secret);

    int code[8];
    code[0] = secret % 2 == 0 ? 1 : 0;
    code[1] = secret % 2 == 0 ? 0 : 1;
    code[2] = secret % 2 == 0 ? (secret % 4 == 0 ? 0 : 1) : (secret % 3 == 0 ? 0 : 1);
    code[3] = secret % 2 == 0 ? (secret % 6 == 0 ? 0 : 1) : (secret % 5 == 0 ? 0 : 1);
    code[4] = secret > 10 ? 0 : 1;
    code[5] = secret > 100 ? 0 : 1;
    code[6] = secret > 1000 ? 0 : 1;
    code[7] = secret > 10000 ? 0 : 1;

    int i = 0;
    for (i = 0; i < 8; i++)
    {
        printf("%d", code[i]);
    }

    return 0;
}