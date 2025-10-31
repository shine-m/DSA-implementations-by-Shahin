#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {

        map<int, vector<int>> vert;
        vector<int> color(n, -1);
        for(auto i: dislikes){
            vert[i[0]].push_back(i[1]);
        }

        queue<int> q;
        q.push(dislikes[0][0]);
        color[dislikes[0][0]] = 0;
        while(!q.empty()){

            for(auto i: vert[q.front()]){
                if(color[i]==color[q.front()])
                    return 0;

                color[i] = 1 - color[q.front()];
                q.push(i);
            }

            
            q.pop();
        }
    }
};

int main()
{
system("cls");
    cout << ln << ln;

    Solution ob;
    string verdict[] = {"false", "true"};
    vector<vector<int>> v = {{1, 2}, {1, 3}, {2, 4}};
    int n = 4;
    cout << verdict[ob.possibleBipartition(n,v)];

    cout
        << ln << ln << ln;
    return 0;
}