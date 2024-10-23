#include <stdio.h>
#include <math.h>

int main()
{
    int n, l, newNum = 0;
    printf("Enter a three digit number : ");
    scanf("%d", &n);
    l = log10(n);
    int i = l;
    if (l + 1 == 3)
    {
        while (n != 0)
        {
            newNum += ((n % 10) * pow(10, i));
            n /= 10;
            i--;
        }
    }
    printf("%d\n", newNum+1);
}