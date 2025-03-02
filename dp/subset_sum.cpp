#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int main()
{
    cout << ln << ln;

    vector<int> v = {0, 3, 2, 4, 3, 2, 1}; // first element should be 0
    int x;
    cout << "numders in given number set :\n";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << ln;
    cout << "enter a number  : \t";
    cin >> x;
    vector<bool> row(x + 1, false);
    row[0] = true;
    vector<vector<bool>> dp(v.size(), row);
    cout << "before \t:\n"; // printing dp values prior calculating
    for (auto j : dp)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }
    // executing dynamic  programmming
    for (int j = 1; j < dp.size(); j++)
    {
        for (int i = 1; i < dp[0].size(); i++)
        {
            if (i >= v[j])
                dp[j][i] = (dp[j - 1][i] || dp[j - 1][i - v[j]]);
            else
                dp[j][i] = dp[j - 1][i];
        }
        cout << ln;
    }
    // printing indices
    cout << "indices :\n";

    for (int i = 0; i < x + 1; i++)
    {
        cout << i << " ";
    }
    cout << ln;
    // printing vector values
    cout << "vector values :\n";

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    cout << "after \t:\n";
    for (auto j : dp)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    cout
        << ln
        << ln
        << ln;
    return 0;
}