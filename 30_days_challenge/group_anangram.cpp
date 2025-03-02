#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> v;

        unordered_map<string, vector<string>> ump;

        for (auto &i : strs)
        {
            string key = i;
            sort(key.begin(), key.end());

            ump[key].push_back(i);
        }

        for (auto i : ump)
        {

            v.push_back(i.second);
        }

        return v;
    }
};
int main()
{

    system("cls");

    Solution ob;
    // vector<string> v = {"bdddddddddd", "bbbbbbbbbbc"};
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> out = ob.groupAnagrams(v);

    for (auto j : out)
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