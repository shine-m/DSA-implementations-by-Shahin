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

class Solution
{
public:
    void island(vector<vector<char>> &grid, int i, int j)
    {

        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            island(grid, i - 1, j);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1')
            island(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1')
            island(grid, i, j - 1);
        if (j + 1 < grid[i].size() && grid[i][j + 1] == '1')
            island(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int result = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    island(grid, i, j);
                }
            }
        }
        return result;
    }
};

int main()
{
    FAST_IO
    PRECISION
    ClearTerminal;
    cout << ln << ln;

    vector<vector<char>> v = {
        {'1', '1', '0', '1', '1', '0', '1'},
        {'0', '0', '0', '1', '1', '0', '0'},
        {'1', '0', '1', '0', '0', '0', '1'}};

    Solution obj;
    cout << obj.numIslands(v);

    for (auto j : v)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    cout << ln << ln << ln;
    return 0;
}