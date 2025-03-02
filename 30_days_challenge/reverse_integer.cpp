#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

class Solution
{
public:
    int reverse(int x)
    {
        int flag = 1;
        long long ans = 0;
        if (x < 0)
            flag = -1;
        long long temp = (long long)x * flag;

        while (temp > 0)
        {
            ans = ans * 10 + (temp % 10);
            temp /= 10;
        }

        ans *= flag;

        if (ans < -2147483648 || ans > 2147483647)

            return 0;

        return ans;
    }
};

int main()
{
    cout << ln << ln;
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution ob;
    cout << ob.reverse(-2147483648) << ln;

    cout << -(long long)pow(2, 31) << " " << (long long)pow(2, 31) - 1;

    cout << ln << ln << ln;
    return 0;
}