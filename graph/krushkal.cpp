#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
#ifdef _WIN32
#define ClearTerminal system("cls")
#endif

class Graph
{
public:
    vector<pair<pair<int, int>, int>> &weightedEdges;
    vector<int> parent, rank;
    int size;
    vector<pair<int, int>> result;
    int vertex_number;
    void krushkal();
    int findParent(int);

    Graph(vector<pair<pair<int, int>, int>> &v) : weightedEdges(v)
    {
        size = v.size();
        parent = vector<int>(size, -1);
        rank = vector<int>(size, 0);
    }
};
int main()
{
    ClearTerminal;
    cout << ln << ln;
    vector<pair<pair<int, int>, int>> v = {{{2, 3}, 2}, {{3, 5}, 4}, {{2, 4}, 1}, {{4, 5}, 3}, {{1, 2}, 3}, {{1, 4}, 3}, {{0, 2}, 2}, {{0, 1}, 1}, {{1, 3}, 1}, {{3, 4}, 2}};

    Graph obj(v);
    obj.krushkal();

    for (auto &[key, value] : obj.result)
    {
        cout << key << " " << value << ln;
    }
    cout << ln;

    cout << ln << ln << ln;
    return 0;
}

void Graph::krushkal()
{

    sort(weightedEdges.begin(), weightedEdges.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    ////////////////this is when  number of vertex is not given////////////;
    unordered_map<int, int> existance;
    for (auto &[key, value] : weightedEdges)
    {
        if (existance[key.first]++)
            vertex_number++;
        if (existance[key.second]++)
            vertex_number++;
    }
    /////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < size && i < vertex_number; i++)
    {
        int parentU = findParent(weightedEdges[i].first.first);
        int parentV = findParent(weightedEdges[i].first.second);
        if (parentU != parentV)
        {
            if (rank[parentU] < rank[parentV])
            {
                parent[parentU] = parentV;
                rank[parentV]++;
                result.push_back({weightedEdges[i].first.second, weightedEdges[i].first.first});
            }
            else
            {
                parent[parentV] = parentU;
                rank[parentU]++;
                result.push_back({weightedEdges[i].first.first, weightedEdges[i].first.second});
            }
        }
    }
}

int Graph::findParent(int x)
{

    while (parent[x] != -1)
    {
        x = parent[x];
    }
    return x;
}