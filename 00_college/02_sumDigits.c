#include <stdio.h>
#include <math.h>

int main()
{
    int n, sum = 0, l;
    printf("Enter a four digit number : ");
    scanf("%d", &n);
    l = log10(n);
    if (l + 1 == 4)
    {
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }

        printf("sum : %d", sum);
    }
    else
    {
        printf("Enter a 4 digit number");
    }
}