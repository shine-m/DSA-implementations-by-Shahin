#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
#ifdef _WIN32
#define ClearTerminal system("cls")
#endif

template <typename l>
long long power(l base, l exp) // exp must be integer here
{
    long long result = 1LL;
    while (exp > 0)
    {
        if (exp & 1)
            result *= base; // multiply when the lowest bit is 1
        base *= base;
        exp >>= 1; // divide exponent by 2
    }
    return result;
}

vector<vector<int>> createSubset(vector<int> &v)
{
    vector<vector<int>> ans;
    int nelements = v.size();
    for (int i = 0; i < static_cast<int>(power(2, nelements)); i++)
    {
        vector<int> temp;
        int k = 1;
        for (int j = 0; j < nelements; j++)
        {
            if (k << j & i)
            {
                temp.push_back(v[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    // ClearTerminal;
    cout << ln << ln;

    vector<int> set = {1, 2, 3};
    vector<vector<int>> subset = createSubset(set);

    for (auto j : subset)
    {
        cout << "{ ";
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << "}";
        cout << ln;
    }

    cout << ln << ln << ln;
    return 0;
}