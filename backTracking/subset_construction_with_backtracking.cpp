#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class set_
{
public:
    vector<vector<int>> results;
    vector<int> &set, temp = {};
    int set_size;
    set_(vector<int> &v) : set(v)
    {
        set_size = set.size();
    }

    void subset(int index)
    {
        cout << "index " << index << " ----> ";
        for (auto i : temp)
        {
            cout << i << " ";
        }
        cout << ln;

        results.push_back(temp);

        for (int i = index; i < set_size; i++)
        {
            temp.push_back(set[i]);
            subset(i + 1);
            // cout << "poppping " << set[i] << ln; // help understand better how the recusrsion works
            temp.pop_back();
        }
    }
};
int main()
{
    system("cls");
    cout << ln << ln;
    vector<int> v = {1, 1, 1, 2, 2};
    set_ obj(v);
    // set_ obj({2, 3, 4, 1});
    // vector<vector<int>>v = obj.subset(0);
    obj.subset(0);

    for (auto &j : obj.results)
    {
        cout << "{ ";
        for (auto &i : j)
        {
            cout << i << " ";
        }
        cout << "}";
        cout << ln;
    }

    cout << ln << ln << ln;
    return 0;
}