#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define loop(n) for (int i = 0; i < n; i++)
#define print(s) cout << s;
typedef long long ll;
int main()
{
    cout << ln << ln;

    vector<int> set1, set2;
    set1 = {2, 5, 4, 2, 4, 2};
    set2 = {5, 2, 3, 1, 2, 5, 2};
    print("initially two lines are\n");

    for (auto i : set1)
        cout << i << " ";
    cout << ln;

    for (auto i : set2)
        cout << i << " ";
    cout << ln;

    vector<int> row(set1.size() + 1, 0);
    vector<vector<int>> dp(set2.size() + 1, row);

    for (int r = 1; r < dp.size(); r++)
    {
        for (int c = 1; c < row.size(); c++)
        {
            if (set1[c - 1] == set2[r - 1])
                dp[r][c] = dp[r - 1][c - 1] + 1;
            else
                dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
        }
    }
    print("the bottom right number signifies the maximum number of uncrossed lines" << ln << ln);
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