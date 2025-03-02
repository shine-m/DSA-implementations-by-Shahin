#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int main()
{
    cout << ln << ln;
    vector<int> v = {3, 5, 8, 3};
    cout << "your set : ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    int n = v.size();
    int x;
    cout << "enter a number to continue \t";
    cin >> x;
    vector<int> row(x + 1, 0);
    row[0] = 1;
    vector<vector<int>> dp(n + 1, row);
    for (int r = 1; r < dp.size(); r++)
        for (int c = 1; c < dp[0].size(); c++)
        {
            if (c - v[r - 1] >= 0)
                dp[r][c] = dp[r - 1][c] + dp[r - 1][c - v[r - 1]];
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

    cout << ln << ln << ln;
    return 0;
}