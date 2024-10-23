#include <stdio.h>

int main()
{
    int arr[6] = {1,2,3,89,5,6},num = 0;
    for(int i = 0; i<6; i++)
    {
        if(i>num)
            num = arr[i];
    }
    printf("%d",num);

}