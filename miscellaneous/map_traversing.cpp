#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
int main()
{
    system("cls");
    cout << ln << ln;

    map<int, int> mp = {{2, 3}, {4, 5}, {3, 3}};

    for (auto &[key, value] : mp)
    {
        cout << key << " " << value << ln;
    }
    cout << ln;

        cout << ln << ln << ln;
    return 0;
}