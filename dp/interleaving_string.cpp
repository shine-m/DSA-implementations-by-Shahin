#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#ifdef _WIN32
#define CLEAR_SCREEN system("cls");
#endif
#define TwoLineVerticalSpace cout << ln << ln;
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class Solution
{
    int i = 0;
    unordered_map<string, pair<bool, bool>> memo;

public:
    string itoa(int num)
    {
        bool isNegative = false;
        if (num == 0)
            return "0";

        string result;
        while (num > 0)
        {
            int digit = num % 10;
            result.push_back('0' + digit);
            num /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isInterleave(string s1, string s2, string s3, int i1 = 0, int i2 = 0, int i3 = 0)
    {
        // cout << i++ << " " << i1 << " " << i2 << " " << i3 << ln;
        if (s1.size() + s2.size() != s3.size())
            return 0;
        if (i3 == s3.size())
            return 1;
        if (memo[itoa(i1) + "*" + itoa(i2) + "*" + itoa(i3)].first)
        {
            return memo[itoa(i1) + "*" + itoa(i2) + "*" + itoa(i3)].second;
        }

        memo[itoa(i1) + "*" + itoa(i2) + "*" + itoa(i3)].first = 1;
        int det = 0;
        if (i1 < s1.size() && s1[i1] == s3[i3])
        {
            // return
            det = isInterleave(s1, s2, s3, i1 + 1, i2, i3 + 1);
            // cout << "used s1" << ln;
        }
        if (!det && i2 < s2.size() && s2[i2] == s3[i3])
        {
            return (memo[itoa(i1) + "*" + itoa(i2) + "*" + itoa(i3)].second = isInterleave(s1, s2, s3, i1, i2 + 1, i3 + 1));
            // cout << "used s2" << ln;
        }
        return memo[itoa(i1) + "*" + itoa(i2) + "*" + itoa(i3)].second = det;
    }
};

int main()
{
    // CLEAR_SCREEN
    TwoLineVerticalSpace;
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbcbbcac";
    // string s1 = "abc", s2 = "acb", s3 = "abaccb";
    // string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    Solution obj;
    cout << obj.isInterleave(s1, s2, s3);

    TwoLineVerticalSpace;
    return 0;
}