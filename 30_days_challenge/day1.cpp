#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
typedef long long ll;
#define loop(n) for (int i = 0; i < n; i++)
#define clearterminal system("cls")

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int k = 0;
        for (auto i : nums)
        {
            k ^= i;
        }
        return k;
    }
};

int main()
{
    clearterminal;

    vector<int> v = {3, 2, 4, 3, 2, 4, 5};

    Solution ob;
    cout << ob.singleNumber(v);

    return 0;
}
