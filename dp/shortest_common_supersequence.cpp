#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define loop(n) for (int i = 0; i < n; i++)
#define print(s) cout << s;
typedef long long ll;
int main()
{
    cout << ln << ln;
    string str1, str2;
    str1 = "tomaro";
    str2 = "amaro";

    vector<int> row1(str1.length() + 1, 0);
    vector<vector<int>> dp(str2.length() + 1, row1);

    for (int r = 1; r <= str2.length(); r++)
        for (int c = 1; c < str1.length() + 1; c++)
            if (str1[c - 1] == str2[r - 1])
                dp[r][c] = 1 + dp[r - 1][c - 1];
            else
                dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);

    // decoding the resultant longest common subsequence
    int col = str1.length(), row = str2.length();
    string lcs = "";
    while (col > 0 && row > 0)
    {
        if (dp[row][col] != dp[row][col - 1])
        {
            lcs = str1[col - 1] + lcs;
            row--;
        }
        col--;
    }
    cout << "longest common subsequence\t" << lcs << ln;

    // now determining the super - srquence
    string ssq;
    int lcsin = 0, st1in = 0, st2in = 0;
    while (lcs[lcsin])
    {

        while (str1[st1in] != lcs[lcsin])
        {
            ssq += str1[st1in];
            st1in++;
        }
        while (str2[st2in] != lcs[lcsin])
        {
            ssq += str2[st2in];
            st2in++;
        }
        ssq += lcs[lcsin];
        lcsin++;
        st1in++;
        st2in++;
    }
    cout << "shorest common supersequence\t" << ssq << ln;

    cout << ln << ln << ln;

    return 0;
}