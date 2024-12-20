// 88
//  code
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < m; i++)
        {
            nums2.push_back(nums1[i]);
        }

        for (int i = 0; i < nums2.size() - 1; i++)
        {
            for (int j = 0; j < nums2.size() - 1 - i; j++)
            {
                if (nums2[j] > nums2[j + 1])
                {
                    int temp = nums2[j];
                    nums2[j] = nums2[j + 1];
                    nums2[j + 1] = temp;
                }
            }
        }
        if (nums2[0] > 0)
        {
            for (int i = 0, j = 0; i < nums2.size(); i++)
            {
                if (nums2[i] != 0)
                {
                    nums1[j++] = nums2[i];
                }
            }
        }
        else
        {
            for (int i = 0, j = 0; i < nums2.size(); i++)
            {
                nums1[j++] = nums2[i];
            }
        }
    }
};