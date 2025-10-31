#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

class MinStack
{

public:
    vector<int> v, minv;
    MinStack()
    {
    }

    void push(int val)
    {
        v.push_back(val);
        if (!minv.size() || val < minv[minv.size() - 1])
            minv.push_back(val);
        else
            minv.push_back(minv[minv.size() - 1]);
    }

    void pop()
    {
        if (v.size())
        {
            v.pop_back();
            minv.pop_back();
        }
    }

    int top()
    {
        if (v.size())
            return this->v[this->v.size() - 1];
        return NULL;
    }

    int getMin()
    {
        if (minv.size())
            return minv[minv.size() - 1];
        return NULL;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{

    cout << ln << ln;
    MinStack *ms = new MinStack();
    ms->push(3);
    cout << ms->v.size() << ln;
    cout << ms->top();

    cout << ln << ln << ln;
    return 0;
}