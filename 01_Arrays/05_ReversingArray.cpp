// todo: to reverse an array

#include <iostream>
#include <vector>
using namespace std;

int reverse_array(vector<int> arr)
{
    int max_len = arr.size() - 1; // last index of the array
    for (int i = 0; i < arr.size() / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[max_len];
        arr[max_len] = temp;
        max_len--;
    }

    for (int i : arr)
        cout << i << " ";
}

int main()
{
    vector<int> array = {2, 3, 4, 5, 9};
    reverse_array(array);
}
