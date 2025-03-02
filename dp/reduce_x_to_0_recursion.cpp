#include <bits/stdc++.h>
#define ln "\n"
typedef long long ll;
#define print(s) cout << s;
#define linegap cout << ln << ln;
#define loop(n) for (int i = 0; i < n; i++)
using namespace std;
vector<int> dp;
int iter = 0;

int reduce(vector<int> &v, int l, int r, int left_over)
{
    iter++;
    if (dp[left_over])
        return dp[left_over];
    if (left_over == 0)
        return 0;
    if (left_over < 0 || l > r)
        return 1e9;
    if (l == r)
    {
        return dp[left_over] = 1 + reduce(v, 1 + l, r, left_over - v[l]);
    }
    if (l < r)
        return dp[left_over] = min(1 + reduce(v, l + 1, r, left_over - v[l]), 1 + reduce(v, l, r - 1, left_over - v[r]));
}
int main()
{
    linegap
        vector<int>
            v = {1, 1, 3, 2, 4, 6};
    print("Given array\t") for (auto i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    int amount;
    print("Enter the amount \t");
    cin >> amount;
    vector<int> tmp(amount + 1);
    dp = tmp;
    int operations = reduce(v, 0, v.size() - 1, amount);
    if (operations > 1e9)
        print("impossible" << ln) else print("number of array elements used atleast\t" << operations << ln)
            print("nuber of iteration\t" << iter << ln)
                linegap return 0;
}