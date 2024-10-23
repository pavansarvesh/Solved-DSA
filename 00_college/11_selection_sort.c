#include <stdio.h>

int main()
{
    int n,temp;
    printf("Enter size :");
    scanf("%d", &n);
    int array[n];

    // Getting input
    for (int i = 0; i < n; i++)
    {
        printf("Enter index %d : ", i);
        scanf("%d", &array[i]);
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d   ", array[i]);
    }
}