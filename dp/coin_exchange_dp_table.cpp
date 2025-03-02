#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
typedef long long ll;
// each of coin denominator can be acccessed infinite number of times
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<int> coins = {10, 5, 2, 1};
    int size = coins.size();
    int amount;
    cout << "enter amount total :\t";
    cin >> amount;
    vector<int> row(amount + 1, amount + 1); // here amount+1 represents infinity as each coin is an integer , so the amount of coin needed can be maximum amount// amount is taken to visualize the 2d array dp on terminal convinently
    row[0] = 0;
    vector<vector<int>> dp(size + 1, row);
    for (int r = 1; r <= size; r++)
    {
        for (int c = 1; c <= amount; c++)
        {

            if (c >= coins[r - 1])
                dp[r][c] = min(dp[r - 1][c], 1 + dp[r][c - coins[r - 1]]);
            else
                dp[r][c] = dp[r - 1][c];
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

    cout << "so the minimum number of coin is " << dp[size][amount] << ln;

    return 0;
}