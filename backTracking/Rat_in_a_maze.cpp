#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class Solution
{
public:
    int size;
    vector<vector<int>> &maze;
    vector<string> paths;
    string currentpath;
    void printMaze();
    void printPaths();
    void backTrack(int, int);

    int count = 0;
    Solution(vector<vector<int>> &v) : maze(v), size(v.size()) {}
};
int main()
{
    system("cls");
    cout << ln << ln;
    vector<vector<int>> v{{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 1, 0, 1}, {0, 0, 0, 1}};

    Solution obj(v);

    obj.printMaze();
    obj.backTrack(0, 0);
    cout << ln;
    cout << where(obj.paths.size(), "the paths are\n", "Any path didn't reach the end\n");
    obj.printPaths();
    cout << "number of iterations \t" << obj.count << ln;

    cout << ln << ln << ln;
    return 0;
}
void Solution::printPaths()
{
    for (auto &i : paths)
    {
        cout << i << " \n";
    }
    cout << ln;
}
void Solution ::printMaze()
{
    cout << "The maze\n";
    for (const auto j : this->maze)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }
}
void Solution ::backTrack(int row, int col)
{
    count++;
    if (row == (size - 1) && col == size - 1)
    {
        paths.push_back(currentpath);
        return;
    }
    int temp = maze[row][col];
    maze[row][col] = 0;

    if (row > 0 && maze[row - 1][col])
    {
        // cout << currentpath << ln;

        currentpath.push_back('U');
        backTrack(row - 1, col);
        currentpath.pop_back();
    }
    if (row < size - 1 && maze[row + 1][col])
    {

        currentpath.push_back('D');
        backTrack(row + 1, col);
        currentpath.pop_back();
    }
    if (col < size - 1 && maze[row][col + 1])
    {

        currentpath.push_back('R');
        backTrack(row, col + 1);
        currentpath.pop_back();
    }
    if (col > 0 && maze[row][col - 1])
    {

        currentpath.push_back('L');
        backTrack(row, col - 1);
        currentpath.pop_back();
    }
    maze[row][col] = temp;
}