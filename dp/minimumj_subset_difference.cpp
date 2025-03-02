#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int main()
{
    cout << ln << ln;
    vector<int> v = {3, 4, 2, 2};
    int n = v.size();
    int sum = 0;
    for (auto i : v)
    {
        sum += i;
    }

    vector<bool> row(sum / 2 + 1, false);
    row[0] = true;
    vector<vector<bool>> dp(n + 1, row);
    for (int r = 1; r < dp.size(); r++)
    {
        for (int c = 1; c < dp[0].size(); c++)
            if (c - v[r - 1] >= 0)
                dp[r][c] = (dp[r - 1][c] || dp[r - 1][c - v[r - 1]]);
            else
                dp[r][c] = dp[r - 1][c];
    }
    int k;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            k = i;
            break;
        }
    }
    for (auto j : dp)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    cout << "disrance =\t" << sum - 2 * k;

    cout << ln << ln << ln;
    return 0;
}