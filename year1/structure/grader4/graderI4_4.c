#include <stdio.h>

int main()
{
    int i = 0, product = 0, inp = 0;
    for (i = 0; i < 7; i++)
    {
        scanf("%d", &inp);
        product += inp;
    }

    int price = 0;
    if (product < 100)
    {
        price = product * 80;
    }
    else if (product < 250)
    {
        price = 100 * 80;
        price += (product - 100) * 70;
    }
    else
    {
        price = 100 * 80;
        price += (product - 100) * 70;
        price += (product - 250) * 60;
    }

    printf("%d\n", price);
    printf("%d\n", product * 100);
    printf("%d", (product * 100) - price);
    return 0;
}