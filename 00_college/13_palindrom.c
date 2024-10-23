#include <stdio.h>

int main()
{
    int num;
    printf("Enter num : ");
    scanf("%d",&num);
    int count = 0,digit, final = 0, n = num;

    while (num != 0)
    {
        digit = num % 10;
        final = (10 * final) + digit;
        num /= 10;
    }
    if (n == final)
    {
        printf("Palindrome");
    }
    else
    {
        printf("No");
    }
}