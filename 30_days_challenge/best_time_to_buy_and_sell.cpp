#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
typedef long long ll;
#define loop(n) for (int i = 0; i < n; i++)
#define clearterminal system("cls")

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {

            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};

int main()
{
    clearterminal;

    // vector<int> v = {10, 8, 4};
    // vector<int> v = {7, 6, 4, 3, 1};
    // vector<int> v = {7, 5, 2, 7, 8, 4};
    vector<int> v = {7, 5, 2, 12, 7, 8, 4};
    Solution ob;
    cout << ob.maxProfit(v);

    return 0;
}
