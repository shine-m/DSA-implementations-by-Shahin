// this code will use dfs strategy
#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
static int checked, det = 0;

vector<string> seq;

class vertex
{
public:
    string color, val;
    int start, finish;
    vector<string> adjacent;
    vertex()
    {
        color = "pink";
        start = 0;
        finish = 0;
    }
};

void dfs(unordered_map<string, vertex> &vtx, string s)
{

    cout << "* " << s << "=> ";
    for (auto i : vtx[s].adjacent)
    {
        vtx[s].color = "black";
        if (vtx[i].color == "pink")
        {
            seq.push_back(vtx[i].val);
            ++checked;
            dfs(vtx, i);
        }
        else
        {
            det = 1;
            // cycle detected
            return;
        }
    }
    vtx[s].color = "pink";
    ++checked;
}

int main()
{
    cout << ln << ln;

    unordered_map<string, vertex> vtx;
    string u, v;

    int n;
    cout << "Enter the number of  Edge : ";
    cin >> n;
    cout << "\nInsert pair of vertices for each of  " << n << " vertices" << ln;

    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        vtx[u].adjacent.push_back(v);
        if (vtx[u].val == "\0")
            vtx[u].val = u;
        if (vtx[v].val == "\0")
            vtx[v].val = v;
    }

    cout << "All verticees are :  ";
    for (auto i : vtx)
    {
        cout << i.first << " ";
    }
    cout << ln;

    // cout << "Enter a vertex to initiate depth first search  : ";
    // cin >> u;
    // dfs(vtx, u);

    for (auto u : vtx)
    {
        vtx[u.first].start = checked = 1;
        dfs(vtx, u.first);
        vtx[u.first].finish = checked;
        if (det)
        {
            cout << "cycle detected for " << u.first << ln;
            break;
        }

        cout << ln;
    }
    cout << "After performing dfs \n\n";
    for (auto i : vtx)
    {
        cout << "vertex :  " << i.second.val << ln;
        cout << "colour : " << i.second.color << ln;
        cout << "start : " << i.second.start << ln;
        cout << "finish : " << i.second.finish << ln;
        cout << ln << ln;
    }

    cout << ln << ln << ln;
    return 0;
}
