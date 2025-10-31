#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {

        vector<int> v(nums.size());
        int cur_index = 0, num_equal = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                v[cur_index++] = nums[i];
            }
            else if (nums[i] == pivot)
                num_equal++;
        }
        while (num_equal--)
        {
            v[cur_index++] = pivot;
        }

        cur_index = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > pivot)
                v[cur_index--] = nums[i];
        }
        return v;
    }
};
int main()
{
    cout << ln << ln;
    vector<int> v1 = {-3, 4, 3, 2};

    Solution ob;
    vector<int> v = ob.pivotArray(v1, 2);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    cout << ln << ln << ln;
    return 0;
}