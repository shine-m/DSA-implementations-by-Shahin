#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
typedef long long ll;
#define loop(n) for (int i = 0; i < n; i++)
#define clearterminal system("cls")

struct compact
{
    int starting = 1, ending, sum;
};

compact kadenis_algo(vector<int> &v)
{
    compact temp;
    int current_sum = 0, max_sum = INT_MIN, index = 1;
    for (auto i : v)
    {
        current_sum += i;
        if (i > current_sum)
        {
            current_sum = i;
            temp.starting = index;
        }
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            temp.ending = index;
            temp.sum = max_sum;
        }

        index++;
    }

    return temp;
}
int main()
{
    clearterminal;

    vector<int> v = {4, -5, 3, -5, 8, 7, -3, -3, 6, -4, 2, 8, -7, 8, -30, 35, 5};

    compact res = kadenis_algo(v);

    cout << "resulting max  " << res.sum << "\nfrom index  " << res.starting << "\t " << res.ending << ln;

    return 0;
}
