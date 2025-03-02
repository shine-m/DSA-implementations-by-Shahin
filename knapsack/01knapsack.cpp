#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
class knap
{
public:
    int weight, profit;
    knap(int w, int p)
    {
        weight = w;
        profit = p;
    }
};
int main()
{
    cout << ln << ln;

    // for(auto i : object){
    //     cout << i.weight << " " << i.profit << ln;
    // }
    // cout << ln;

    vector<knap> object = {knap(2, 1), knap(3, 2), knap(4, 5), knap(5, 6)};
    int n = object.size();
    int w;
    cout << "ENTER THE SIZE OF THE  KNAPSACK\t";
    cin >> w;
    vector<int> vect(w + 1, 0);
    vector<vector<int>> v(n + 1, vect);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j - object[i - 1].weight >= 0)
                v[i][j] = max(v[i - 1][j], v[i - 1][j - object[i - 1].weight] + object[i - 1].profit);
            else
                v[i][j] = v[i - 1][j];
        }
    }

    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << ln;
    }
    cout << ln;

    cout << ln << ln << ln;
    return 0;
}