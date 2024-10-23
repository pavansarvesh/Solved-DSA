#include <stdio.h>

int main()
{
    int low = 0, high = 0, mid = 0, n = 4;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    high = sizeof(arr) / sizeof(arr[0]);

    if (n > arr[high - 1])
    {
        printf("Element NOT FOUND :(");
    }
    else
    {
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] == n)
            {
                printf("index : %d", mid);
                break;
            }
            else if (arr[mid] < n)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
    }
}