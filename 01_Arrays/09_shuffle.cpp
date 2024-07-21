#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> v;
        int i, j;
        for (i = 0, j = n; i < n; i++, j++)
        {
            v.push_back(nums[i]);
            v.push_back(nums[j]);
        }
        return v;
    }
};

int main()
{
    Solution shuffle;
    vector<int> array = {2, 3, 5, 4, 1, 7};
    array = shuffle.shuffle(array,3);
    for (int i : array)
    {
        cout << i << " ";
    }
}