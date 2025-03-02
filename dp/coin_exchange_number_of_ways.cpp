#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
typedef long long ll;
int main()
{
    cout << ln << ln;
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int amount;
    cout << "input deaired amount ";
    cin >> amount;
    vector<int> coin = {1, 2, 5};
    int total_coin = coin.size();

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= total_coin; i++)
    {
        for (int c = 1; c <= amount; c++)
        {
            if (coin[i - 1] <= c)
            {
                dp[c] = dp[c] + dp[c - coin[i - 1]];
            }
        }
        for (auto i : dp)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    cout << ln << ln << ln;
    return 0;
}