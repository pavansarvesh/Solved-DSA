#include <stdio.h>

int main()
{
    int n, a = 0, b = 1, c = 0;
    printf("Enter a number : ");
    scanf("%d", &n);
    while (c <= n)
    {
        c = a + b;
        // printf("%d  ",c);
        if (n == c || n == 0 || n == 1)
        {
            a = 1;
            break;
        }
        a = b;
        b = c;
    }
    if (a == 1)
    {
        printf("it is a fib number");
    }
    else
    {
        printf("it is not a fib number");
    }
}