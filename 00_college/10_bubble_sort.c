#include <stdio.h>

int main()
{
    int n;

    printf("ent size :");
    scanf("%d", &n);
    int array[n];

    // Getting input
    for (int i = 0; i < n; i++)
    {
        printf("Enter index %d : ", i);
        scanf("%d", &array[i]);
    }

    // printing unsorted
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    // Sorting

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d \t", array[i]);
            }
            printf("\n");
        }
    }
}