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

                int dir = 0; // dir for direction. uppper direction and lower directions are indicated using  0 and 1
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

    Solution ob;
    cout << ob.convert("PAYPALISHIRING", 40);

    cout << ln << ln << ln;
    return 0;
}