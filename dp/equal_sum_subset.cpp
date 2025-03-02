#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int main()
{
    cout << ln << ln;

    vector<int> v = {3, 8, 4, 4, 13};

    int n = v.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }

    if (sum & 1)
    {

        cout << "can not be partitioned\n";
        return 0;
    }
    sum /= 2;
    vector<bool> row(sum + 1, false);
    row[0] = true;
    vector<vector<bool>> dp(n + 1, row);
    for (int r = 1; r < dp.size(); r++)
        for (int c = 1; c < dp[0].size(); c++)
        {
            if (c - v[r - 1] >= 0)
            {
                dp[r][c] = (dp[r - 1][c] || dp[r - 1][c - v[r - 1]]);
            }
            else
                dp[r][c] = dp[r - 1][c];
        }

    for (auto j : dp)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    if (dp[n][sum])
    {
        cout << "subset can be formed\n";
        vector<int> ans;
        while (n)
        {
            if (n > 0 && dp[n - 1][sum])
                n--;
            else
            {
                ans.push_back(v[n - 1]);
                sum -= v[n - 1];
                n--;
            }
        }
        cout << "the subset is :\t";
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    cout << ln << ln << ln;
    return 0;
}