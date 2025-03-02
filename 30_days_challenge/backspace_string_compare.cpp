#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        queue<char> news, newt;

        int n_backspace = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '#')
                n_backspace++;
            else
            {
                if (n_backspace == 0)
                    news.push(s[i]);
                n_backspace = (n_backspace > 0 ? n_backspace - 1 : 0);
            }
        }

        n_backspace = 0;
        for (int i = t.length() - 1; i >= 0; i--)
        {
            if (t[i] == '#')
                n_backspace++;
            else
            {
                if (n_backspace == 0)
                    newt.push(t[i]);
                n_backspace = (n_backspace > 0 ? n_backspace - 1 : 0);
            }
        }
        if (newt.size() != news.size())
            return false;
        else
        {
            char chars, chart;
            while (!newt.empty())
            {
                if (news.front() != newt.front())
                    return false;
                newt.pop();
                news.pop();
            }

            return true;
        }
    }
};

int main()
{
    string verdict[] = {"false", "true"};
    cout << ln << ln;
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string s = "d#hk##U#", t = "###fyg###";

    Solution ob;
    cout << verdict[ob.backspaceCompare(s, t)] << ln;

    cout << ln << ln << ln;
    return 0;
}