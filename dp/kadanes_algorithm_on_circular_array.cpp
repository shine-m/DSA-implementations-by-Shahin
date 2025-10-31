#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#ifdef _WIN32
#define ClearTerminal system("cls")
#endif
int main()
{
    FAST_IO
    PRECISION
    ClearTerminal;
    cout << ln << ln;

    vector<int> v = {5, -3, -2, 6, -1, 4};
    // vector<int> v = {-2, -3, -1, -4};
    int n = v.size();
    int cursum = 0, net_result = INT_MIN;
    for (int i = 0; i < 2 * n - 1; i++) // here  n+ (n-1) = 2*n-1 ; extra n-1 is for pretending  circularity
    {
        cursum += v[i % n]; // mod is taken for i values greater or equal than n, as v has index till n-1 but i will iterate up to 2n-1(exclusive)

        net_result = max(net_result, cursum); // this line must be prior to the following if statement because there can be an arry containing negative arrays only

        if (cursum < 0)
            cursum = 0;
    }

    cout << net_result << ln;

    cout << ln << ln << ln;
    return 0;
}