#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#ifdef _WIN32
#define ClearTerminal() system("cls")
#endif
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class Solution
{
    vector<pair<int, int>> &edges;
    vector<vector<int>> adjacency_list;
    stack<int> topological_order;
    void topological(int);
    bool cycle_detected = 0;

public:
    vector<int> processing, processed, indegree;
    Solution(vector<pair<int, int>> &edges) : edges(edges)
    {
        adjacency_list = vector<vector<int>>(edges.size() + 2); // extra 1 (for n edge , n+1 vertices) and another 1 for excluding 0 th index as vertices are 1 through n
        indegree = vector<int>(edges.size() + 2);
        for (auto &[u, v] : edges)
        {
            adjacency_list[u].push_back(v);
            indegree[v]++;
        }
    };
    void printEdges()
    {
        cout << "Printing Edges\n";

        for (auto &[key, value] : edges)
        {
            cout << key << " " << value << ln;
        }
        cout << ln;
    }
    void printAdj()
    {
        cout << "Printing Adjecency List\n";
        int i = 0;
        for (auto &list : adjacency_list)
        {
            cout << i++ << " \t";
            for (auto j : list)
            {
                cout << j << " ";
            }
            cout << ln;
        }
        cout << ln;
    }
    void solve()
    {

        processed = processing = vector<int>(edges.size() + 2, 0);

        for (int i = 0; i < adjacency_list.size() && !cycle_detected; i++)
            if (adjacency_list[i].size() && indegree[i] == 0) // because there will be several dummy vertices created who does not have adjacency list, we dont want to add them in the topological list
                topological(i);

        if (!cycle_detected)
        {

            cout << "topological order\n";
            while (!topological_order.empty())
            {
                cout << topological_order.top() << " ";
                topological_order.pop();
            }
        }
        else
            cout << "Cycle detected, Topologival sort impossible\n";
    }
};
int main()
{
    ClearTerminal();

    cout << ln << ln;

    vector<pair<int, int>> edges = {{1, 2}, {1, 4}, {0, 5}, {2, 3}, {2, 4}, {3, 5}, {4, 5}, {6, 3}};
    Solution obj(edges);
    obj.printEdges();
    obj.printAdj();
    obj.solve();

    cout << ln << ln << ln;
    return 0;
}

void Solution::topological(int ith)
{
    // cout << "called for\t" << ith << ln;
    if (processed[ith])
    {
        return;
    }

    if (processing[ith])
    {
        // cout << "Cycle exists\tat node\t" << ith;//just in case we want to know where the cycle detected
        cycle_detected = 1;
        return;
    }

    processing[ith] = 1;
    for (int i = 0; i < adjacency_list[ith].size() && !cycle_detected; i++)
    {

        topological(adjacency_list[ith][i]);
    }

    topological_order.push(ith);
    processed[ith] = 1;
    processing[ith] = 0; // this line was redundant as processed=1 and it will never get into function again
}