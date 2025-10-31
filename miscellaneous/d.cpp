#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        int x;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        int maxx = 0, l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int tradeoff = 0, benefits = 0;
            while (j < n)
            {
                benefits += v[i] > v[j];
                tradeoff += v[i] < v[j];
                if (maxx < benefits - tradeoff)
                {
                    maxx = benefits - tradeoff;
                    l = i;
                    r = j;
                }
                j++;
            }
        }

        cout << l + 1 << " " << r + 1 << ln;
    }
    return 0;
}