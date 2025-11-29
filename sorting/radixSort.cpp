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

void RadixSort(vector<int> &v)
{

    int maxel = *max_element(v.begin(), v.end());

    int exp = 1;
    vector<int> final(v.size());
    while (maxel > 0)
    {

        vector<int> freq(10, 0);
        for (int i = 0; i < v.size(); i++)
        {

            int digit_to_consider = v[i] / exp % 10;
            freq[digit_to_consider]++;
        }
        for (int i = 1; i < 10; i++)
        {
            freq[i] += freq[i - 1];
        }

        for (int i = v.size() - 1; i > -1; i--)
        {
            int digit_to_consider = v[i] / exp % 10;

            final[freq[digit_to_consider] - 1] = v[i];
            freq[digit_to_consider]--;
        }
        v.swap(final);
        maxel /= 10;
        exp *= 10;
        // to show the process iteration
        // for (auto &i : final)
        // {
        //     cout << i << " ";
        // }
        // cout << ln;
    }
}

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<int> v = {3, 54, 2, 32, 1, 5, 53, 2, 166, 17};
    RadixSort(v);
    cout << "after sorting \n=> ";
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << ln;

    TwoLineVerticalSpace;
    return 0;
}