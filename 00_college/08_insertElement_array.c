#include <stdio.h>

int main()
{
    int max_size, *ptr,num,index = 0,temp;
    printf("size of the array :");
    scanf("%d", &max_size);
    int array[max_size + 1];
    ptr = array;
    for (int i = 0; i < max_size; i++)
    {
        printf("Enter arr[%d] : ", i);
        scanf("%d", &array[i]);
    }

    printf("Enter the num to be entered :");
    scanf("%d", &num);
    printf("Enter Index :");
    scanf("%d", &index);

    for (int i = max_size + 1; i >= 0; i--)
    {
        array[i] = array[i-1];
        if(index == i){
            temp = array[index];
            array[index] = num;
            array[index - 1] = temp;
            i-=3;
        }
    }

    for (int i = 0; i < max_size+1; i++)
    {
        printf("%d   ", array[i]);
    }
}