#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

class Solution
{
public:
    string longestPalindrome(string s)
    {
        vector<int> v(s.length());
        vector<vector<int>> dp(s.length(), v);
        int maxx = 1, l = 0, r = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {

            dp[i][i] = 1;

            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                maxx = 2;
                l = i;
            }
        }

        if (maxx == 2)
        {
            r = l + 1;
        }
        dp[s.length() - 1][s.length() - 1] = 1;

        for (int i = 2; i < s.length(); i++)
        {
            for (int j = 0; j < s.length() - i; j++)
            {

                if (s[j] == s[j + i] && dp[j + 1][j + i - 1])
                {
                    dp[j][j + i] = 1;
                    if (i + 1 > maxx)
                    {
                        l = j;
                        r = j + i;
                        maxx = i + 1;
                        // cout << "entered for " << i << ln;
                    }
                }
            }
        }
        // for (auto j : dp)
        // {
        //     for (auto i : j)
        //     {
        //         cout << i << " ";
        //     }
        //     cout << ln;
        // }
        // cout << l << " " << r << ln;
        return string(s.begin() + l, s.begin() + r + 1);
    }
};

int main()
{
    cout << ln << ln;
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string s = "cbbcc";

    Solution ob;
    cout << ob.longestPalindrome(s);
    cout << ln << ln << ln;
    return 0;
}