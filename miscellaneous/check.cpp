#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
int main()
{
    system("cls");
    cout << ln << ln;

    vector<int> v = {3, 2, 5, 3, 3, 4, 2, 1};
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    sort(v.begin(), v.end());

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    cout << "distance=\t" << lower_bound(v.begin(), v.end(), 1) - v.begin();

    cout << ln << ln << ln;
    return 0;
}