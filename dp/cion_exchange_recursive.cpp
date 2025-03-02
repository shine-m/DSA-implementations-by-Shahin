#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int n, iter = 0, iterdp = 0;
vector<int> dp(1000000, -1); // for dp

int coin_exchange_withdp(vector<int> &v, int left, int i)
{
    iterdp++;
    if (dp[left] != -1)
    {
        return dp[left];
    }

    if (i >= n)
        return 1e9;
    if (v[i] > left)
        return dp[left] = coin_exchange_withdp(v, left, i + 1);
    else
        return dp[left] = min(coin_exchange_withdp(v, left, i + 1), 1 + coin_exchange_withdp(v, left - v[i], i));
}
int coin_exchange(vector<int> &v, int left, int i)
{
    iter++;
    if (left == 0)
    {
        return 0;
    }
    if (i >= n)
        return 1e9;
    if (v[i] > left)
        return coin_exchange(v, left, i + 1);

    return min(coin_exchange(v, left, i + 1), 1 + coin_exchange(v, left - v[i], i));
}
int main()
{
    cout << ln << ln;
    dp[0] = 0;
    int amount;
    cout << "Enter desired amount\t";
    cin >> amount;
    int ans = 0;
    vector<int> v = {10, 50, 5, 3};
    n = v.size();
    // without dp
    cout << "minimum number of coins\t";
    cout << coin_exchange(v, amount, 0) << ln;
    cout << "nuber of iterations\t" << iter << ln;
    // with dp
    cout << "minimum number of coins\t";
    cout << coin_exchange_withdp(v, amount, 0) << ln;
    cout << "nuber of iterations\t" << iterdp << ln;

    cout << ln << ln << ln;
    return 0;
}