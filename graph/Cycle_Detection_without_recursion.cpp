#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {

        map<int, vector<int>> adjacency_list;
        vector<int> indeg(n + 1);
        vector<int> color(n + 1, -1); //-1 for not touched
        for (auto i : dislikes)
        {

            adjacency_list[i[0]].push_back(i[1]);
        }

        stack<int> stk;

        for (int i = 1; i <= n; i++)
        {
            if (indeg[i])
                ;
            else
            {
                stk.push(i);
            }
        }
        int self_cycle = stk.empty() ? 0 : 1; /// empty stk  means no vertex with in-degree 0

        while (!stk.empty() && self_cycle)
        {

            int current_node = stk.top();

            if (color[current_node] == 0)
            {

                stk.pop();
                continue;
            }

            cout << current_node << " -> ";
            if (color[current_node] == -1)
            {

                color[current_node] = 1; // precessing
                for (auto &i : adjacency_list[current_node])
                {

                    if (color[i] == 1)
                    {
                        self_cycle = 0;
                        break;
                    }
                    else if (color[i] == -1)
                        stk.push(i);
                }
            }
            else if (color[current_node] == 1)
            {

                color[current_node] = 0; // processed
                stk.pop();
            }
        }
        return self_cycle;
    }
};

int main()
{
    system("cls");
    cout << ln << ln;

    string verdict[] = {"false", "true"};
    vector<vector<int>> v = {{1, 2}, {1, 3}, {2, 4}, {4, 1}};
    int n = 4;
    cout << verdict[Solution().possibleBipartition(n, v)];

    cout << ln << ln << ln;
    return 0;
}