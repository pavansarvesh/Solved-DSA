#include <stdio.h>

int main()
{
    int arr[100],por,max_size;
    printf("size of the array :");
    scanf("%d", &max_size);
    int array[max_size + 1];
    for (int i = 0; i < max_size; i++)
    {
        printf("Enter arr[%d] : ", i);
        scanf("%d", &array[i]);
    }

    printf("Enter the index where you want to delete : ");
    scanf("%d",&por);
    if(por>= max_size+1)
    {
        printf("Deletion Not Possible");
    } else {
        for(int i = por; i < max_size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        printf("Resulted Array");
    }

    for (int i = 0; i < max_size - 1; i++)
    {
        printf("%d   ", array[i]);
    }
}
