#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#ifdef _WIN32
#define ClearTerminal system("cls")
#endif
// deleting..........
class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int l = 0, r = heights.size() - 1;
        long long ans = -1;
        while (l < r)
        {
            ans = max(ans, (long long)min(heights[l], heights[r]) * (r - l));
            heights[l] > heights[r] ? (r--) : (l++);
        }
        return ans;
    }
};

int main()
{
    FAST_IO
    PRECISION
    ClearTerminal;
    cout << ln << ln;

    Solution obj;
    // vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> v = {1, 2, 1};
    cout << obj.maxArea(v) << ln;

    cout << ln << ln << ln;
    return 0;
}