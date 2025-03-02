#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string res;
        for (int i = 1; i <= numRows && i <= s.length(); i++)
        {
            int cur = i - 1;

            if (i == 1 || i == numRows)
            {

                while (cur < s.length())
                {

                    res += s[cur];
                    cur = cur + (numRows - 1) * 2;
                }
            }
            else
            {

                int dir = 0;
                while (cur < s.length())
                {

                    res += s[cur];

                    if (dir)
                    {
                        cur = cur + (i - 1) * 2;
                        dir = 0;
                    }
                    else
                    {
                        cur = cur + (numRows - i) * 2;
                        dir = 1;
                    }
                }
            }
        }
        return res;
    }
};
int main()
{
    cout << ln << ln;
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Solution ob;
    cout << ob.convert("PAYPALISHIRING", 40);

    cout << ln << ln << ln;
    return 0;
}