#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#ifdef _WIN32
#define CLEAR_SCREEN system("cls");
#endif
#define TwoLineVerticalSpace cout << ln << ln;
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
using ll = long long;

void bubbleSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
    }
}
int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<int> v = {3, 1, 5, 4, 1};
    bubbleSort(v);
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    TwoLineVerticalSpace;
    return 0;
}