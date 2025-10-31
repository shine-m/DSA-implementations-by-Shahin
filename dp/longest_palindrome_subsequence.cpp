#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while (t--)
    {

        string s;
        cin >> s;
        int n = s.length();
        vector<bool> b(n, false);
        vector<vector<bool>> v(n, b);

        int start = 0, end = 0, max = 0;
        for (int i = 0; i < s.length(); i++)
        {

            v[i][i] = 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                v[i][i + 1] = 1;
                start = i;
                end = i + 1;
                max = 1;
            }
        }
        for (int i = 2; i < n; i++)
        {
            for (int k = 0; k < n - i; k++)
            {
                if (s[k] == s[k + i] && v[k + 1][k + i - 1])
                {
                    v[k][k + i] = 1;
                    if (i > max)
                    {
                        start = k;
                        end = k + i;
                        max = i;
                    }
                }
            }
        }
        for (auto j : v)
        {
            for (auto i : j)
            {
                cout << i << " ";
            }
            cout << ln;
        }
        cout << "maximum palindromic subarray is from index " << start << " to " << end << ln;
    }
    return 0;
}