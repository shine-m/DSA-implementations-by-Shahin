#include <bits/stdc++.h>
#define ln "\n"
typedef long long ll;
#define print(s) cout << s;
#define linegap cout << ln << ln;
#define loop(n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{

    string s1, s2;
    s1 = "asdomnbo";
    s2 = "qdooepli";
    vector<int> row(s1.length() + 1, 0);
    vector<vector<int>> dp(s2.length() + 1, row);
    for (int i = 1; i <= s2.length(); i++)
    {
        for (int j = 1; j <= s1.length(); j++)
        {
            if (s1[j - 1] == s2[i - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (auto j : dp)
    {
        for (auto i : j)
            cout << i << " ";
        cout << ln;
    }

    // determining the resultant subsequent string
    string ans;
    int r = s2.length(), col = s1.length();

    while (col > 0 && r > 0)
    {

        if (dp[r][col] != dp[r][col - 1])
        //  if( dp[r][col] > dp[r - 1][col - 1])   my this assumption was erroneous
        {
            ans = s1[col - 1] + ans;
            r--;
        }
        col--;
    }
    cout << "loop ended   ";
    cout << " the longest common subsequence\t:\t";
    cout << ans;
    return 0;
}