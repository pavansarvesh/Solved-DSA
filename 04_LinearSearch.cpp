// Linear Search
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num;

    cout << "Enter a number : ";
    cin >> num;

    for (int i = 0; i < arr.size(); i++)
        if (num == arr[i])
        {
            cout << "number " << num << " found at index " << i;
            break;
        }
}