#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int n = nums.size();

        int num_even = 0, num_odd = 0, alternating = 1, need_odd = nums[0] & 1 ? 0 : 1;

        for (int i = 0; i < n; i++)
        {

            if (nums[i] & 1)
            {
                num_odd++;
                if (need_odd)
                {
                    need_odd = 1 - need_odd;
                    alternating++;
                }
            }
            else
            {
                num_even++;
                if (!need_odd)
                {
                    alternating++;
                    need_odd = 1 - need_odd;
                }
            }
        }

        return max(alternating, max(num_odd, num_even));
    }
};

int main()
{
    system("cls");
    cout << ln << ln;

    vector<int> v = {3, 2};

    Solution obj;
    cout << obj.maximumLength(v);

    cout << ln << ln << ln;
    return 0;
}