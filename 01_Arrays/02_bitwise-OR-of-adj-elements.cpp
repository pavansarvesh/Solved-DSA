#include <iostream>
#define MAX 5

int bitwiseOR(int num)
{
    int num1 = 1;
    // std::cout << "Enter a Number : ";
    // std::cin >> num;
    num1 += num;
    return num | num1;
}

int main()
{
    int arr[MAX], arr1[MAX];

    // Enter the values in arr
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter a arr[%d] : ", i);
        std::cin >> arr[i];
        arr1[i] = bitwiseOR(arr[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        std::cout << arr1[i] << " ";
    }
}