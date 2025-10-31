#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> pos;
        int start = 0, max_len = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if (pos[s[i]] - 1 >= start)
            {
                max_len = max(max_len, (i - start));
                start = pos[s[i]];
            }
            pos[s[i]] = i + 1;
        }
        return max(max_len, int(s.length() - start));
    }
};
int main()
{

    string s = "  asdfasdftm";
    // string s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    Solution ob;
    cout << ob.lengthOfLongestSubstring(s);
    return 0;
}