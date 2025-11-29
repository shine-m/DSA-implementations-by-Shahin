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

void bucketSort(vector<int> &v)
{

    int maxel = *max_element(v.begin(), v.end());
    vector<int> bucket(maxel + 1);
    for (int i = 0; i < v.size(); i++)
    {
        bucket[v[i]]++;
    }
    for (int i = 1; i < bucket.size(); i++)
    {
        bucket[i] += bucket[i - 1];
    }

    vector<int> output(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        output[bucket[v[i]] - 1] = v[i];
        bucket[v[i]]--;
    }
    v.swap(output);
}

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<int> v = {3, 54, 2, 3, 1, 5, 3, 2, 6, 7};
    bucketSort(v);
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    TwoLineVerticalSpace;
    return 0;
}