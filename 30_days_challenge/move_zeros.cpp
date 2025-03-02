#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
typedef long long ll;
#define loop(n) for (int i = 0; i < n; i++)
#define clearterminal system("cls")

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int zeros = 0, i = 0, curr = 0;
        while (i < n)
        {
            if (nums[i])
            {
                nums[i - zeros] = nums[i];
            }
            else
            {
                zeros++;
            }
            i++;
        }
        i = n - zeros;
        while (i < n)
        {
            nums[i] = 0;
            i++;
        }
    }
};

int main()
{
    clearterminal;

    vector<int> v = {1, 2, 3, 0, 0, 3, 1, 0, 5, 0};
    // vector<int> v = {1, 0};
    Solution ob;
    ob.moveZeroes(v);
    for (auto i : v)
        cout << i << " ";
    cout << ln;

    return 0;
}
