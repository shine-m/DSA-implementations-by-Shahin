#include <bits/stdc++.h>
#define ln "\n"
typedef long long ll;
#define print(s) cout << s;
#define linegap cout << ln << ln;
#define loop(n) for (int i = 0; i < n; i++)
using namespace std;
class parameters
{
public:
    int length, price;
    parameters(int l, int p) : length(l), price(p) {}
};
map<int, pair<bool, int>> dp;
int iteration = 0;
int rod_cutting(deque<parameters> &v, int n)
{
    iteration++;

    if (dp[n].first)
        return dp[n].second;

    int maxx = 0, temp = 0;

    for (int i = n; i > 0; i--)
    {
        if (i >= v.size()) // this if condition enables to calculate for length for which we are not given any initial price
            temp = max(temp, rod_cutting(v, i - 1) + rod_cutting(v, n - i + 1));
        else
            temp = max(temp, v[i].price + rod_cutting(v, n - i));
    }
    dp[n].first = 1;
    return dp[n].second = temp;
}
int main()
{
    linegap

        dp[0]
            .first = 1;
    dp[0].second = 0;
    deque<parameters>
        rod = {{1, 2}, {2, 5}, {3, 9}, {4, 15}};
    rod.push_front({0, 0});
    int size = rod.size();
    print("length - price" << ln);
    for (auto i : rod)
    {
        cout << i.length << " " << i.price << ln;
    }
    cout << ln;

    // cout << rod_cutting(rod, rod.size() - 1) << ln;
    cout << "input any rod length\t";
    int len;
    cin >> len;
    cout << rod_cutting(rod, len) << ln;
    cout << "numberofiteraeteion\t" << iteration << ln;

    linegap return 0;
}