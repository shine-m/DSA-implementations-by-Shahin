#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
int main()
{
    cout << ln << ln;
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    int i = 0;
    int maxx = v[i];
    int jumps = 0;
    int index;
    vector<int> jump;
    jump.push_back(1);
    for (; i <= maxx && i < n + 1; i++)
    {
        if (i + v[i] > maxx)
        {
            maxx = i + v[i];
        }
        // cout << v[i] << " " << maxx << ln;
    }
    cout << (maxx >= n - 1 ? "yes, got away\n" : "no, got stucked\n") << ln;
}
// testcase
// 16 3 2 1 4 5 7 2 1 4 1 2 3 2 0 0 1