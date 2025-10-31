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
    int n;
    vector<int> left_limits, right_limits;
    void create_limits(vector<int> &, vector<int> &, int);

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<int> heights(matrix[0].size(), 0);
        int ans = -1;
        for (auto &i : matrix)
        {
            for (int j = 0; j < i.size(); j++)
            {
                if (i[j] == '1')
                {
                    heights[j]++;
                }
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {

        int ans = -1;
        n = heights.size();
        left_limits = vector<int>(n);
        right_limits = vector<int>(n);

        int isleft = 1;
        create_limits(heights, left_limits, isleft);
        isleft = 0;
        create_limits(heights, right_limits, isleft);

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (right_limits[i] - left_limits[i] + 1));
        }

        return ans;
    }
};

void Solution::create_limits(vector<int> &heights, vector<int> &limits, int isleft)
{

    stack<int> stk;
    int extreme_value = isleft ? 0 : n - 1;

    for (int i = extreme_value; isleft ? i < n : i >= 0; isleft ? i++ : i--)
    {

        if (stk.empty())
        {
            limits[i] = extreme_value;
            stk.push(i);
        }
        else
        {
            if (heights[i] > heights[stk.top()])
            {
                stk.push(i);
                limits[i] = i;
            }
            else
            {

                while (!stk.empty() && heights[stk.top()] >= heights[i])
                {

                    stk.pop();
                }
                if (stk.empty())
                {
                    limits[i] = extreme_value;
                }
                else
                {

                    limits[i] = stk.top() + 1 + 2 * (!isleft * (-1)); // +1 for left limit and -1 for right limit . beacuse the selement in the stack which is less than the current index element will be the boundary, the next element towards the current ith elemeent will be the inclusion limit
                }
                stk.push(i);
            }
        }
    }
}
int main()
{
    FAST_IO
    PRECISION
    // ClearTerminal;
    cout << ln << ln;

    Solution obj;
    // vector<int> v = {2, 1, 5, 6, 2, 3};
    // vector<int> v = {3, 6, 5, 7, 4, 8, 1, 0};
    // cout << obj.largestRectangleArea(v) << ln;

    vector<vector<char>> vs = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << obj.maximalRectangle(vs) << ln;
    cout
        << ln << ln << ln;
    return 0;
}