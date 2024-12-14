#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int arrSize = nums1.size() + nums2.size();
        double result = 0;
        vector<double> newArr;
        for (int i = 0; i < nums1.size(); i++)
        {
            newArr.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            newArr.push_back(nums2[i]);
        }

        for (int i = 0; i < arrSize - 1; i++)
        {
            for (int j = 0; j < arrSize - 1 - i; j++)
            {
                if (newArr[j] > newArr[j + 1])
                {
                    int temp = newArr[j];
                    newArr[j] = newArr[j + 1];
                    newArr[j + 1] = temp;
                }
            }
        }
        if (arrSize % 2 != 0)
        {
            result = newArr[arrSize / 2];
        }
        else
        {
            arrSize--;
            result = (newArr[(arrSize) / 2] + newArr[((arrSize) / 2) + 1]) / 2;
        }
        return result;
    }
};

int main()
{
    Solution median;
    vector<int> array1 = {1, 2};
    vector<int> array2 = {3, 4};
    double r = median.findMedianSortedArrays(array1, array2);
    cout<< r;
}