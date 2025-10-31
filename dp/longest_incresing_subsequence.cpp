#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
#ifdef _WIN32
#define ClearTerminal system("cls")
#endif
int main()
{
    ClearTerminal;
    cout << ln << ln;

    vector<int> v = {2, 6, 5, 2, 3, 1, 8, 4, 6, 7};
    vector<int> dp(v.size(), 1);
    int maxlen = 0;

    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && dp[i] <= dp[j])
            {
                maxlen = max(maxlen, dp[i] = (1 + dp[j]));
            }
        }
    }
    cout << "dp array\t";
    for (auto i : dp)
    {
        cout << i << " ";
    }
    cout << ln;
    cout << "max length of subsequence is " << maxlen << ln;
    cout << "the sequence is ";
    int curr = maxlen;

    for (int i = v.size() - 1; i >= 0 && curr; i--)
    {
        if (dp[i] == curr)
        {
            cout << v[i] << " ";
            curr--;
        }
    }

    cout << ln;

    cout << ln << ln << ln;
    return 0;
}