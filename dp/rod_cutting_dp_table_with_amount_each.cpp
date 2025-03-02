#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
typedef long long ll;

class parameters
{
public:
    int length, price;
    parameters(int l, int p) : length(l), price(p) {}
};
int main()
{
    cout << ln << ln;

    vector<parameters> rod = {{1, 1}, {2, 3}, {3, 6}, {4, 7}};
    int size = rod.size();
    for (auto i : rod)
    {
        cout << i.length << " " << i.price << ln;
    }
    cout << ln;
    int totallength;
    cout << "enter rod length : ";
    cin >> totallength;
    vector<int> row(totallength + 1, 0);
    vector<vector<int>> dp(size + 1, row);
    vector<int> volume(totallength + 1);
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= totallength; j++)
        {
            if (j >= rod[i - 1].length)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - rod[i - 1].length] + rod[i - 1].price);
                if (dp[i][j] != dp[i - 1][j])      // these two lines are
                    volume[j] = rod[i - 1].length; // for frequency of each length
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    for (auto j : dp)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    cout << ln << ln << ln;
    cout << "Best outcome bearer length for each index \n";

    for (auto i : volume)
    {
        cout << i << " ";
    }
    cout << ln;
    cout << "Selected lengths are : \n";
    for (int i = totallength; i > 0; i -= volume[i])
    {
        cout << volume[i] << " ";
    }

    return 0;
}