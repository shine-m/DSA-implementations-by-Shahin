#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int ans = 0, iter = 0;

void island_count(vector<vector<int>> &v, int i, int j)
{
    iter++;
    v[i][j] = 0;
    if (i - 1 > 0 && v[i - 1][j])

        island_count(v, i - 1, j);

    if (i + 1 < v.size() && v[i + 1][j])
        island_count(v, i + 1, j);
    if (j - 1 > 0 && v[i][j - 1])
        island_count(v, i, j - 1);
    if (j + 1 < v[0].size() && v[i][j + 1])
        island_count(v, i, j + 1);
}
int main()
{
    cout << ln << ln;

    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<vector<int>> v = {
        {
            1,
            1,
            0,
            1,
            1,
            0,
            1,
        },
        {0, 0, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 1}};
    for (auto j : v)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    int k = 0, l;
    for (auto j : v)
    {
        l = 0;
        for (auto i : j)
        {
            if (v[k][l])
            {
                island_count(v, k, l);
                ans++;
            }
            l++;
        }
        k++;
    }

    cout << "number of island\t" << ans << ln;
    cout << "number of iterations\t" << iter << ln;
    cout << "after completion of exploration :\n";
    for (auto j : v)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    cout
        << ln << ln << ln;
    return 0;
}